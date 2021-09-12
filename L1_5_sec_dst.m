clc;
clear all;
close all;

%Fs Hz (samples per second) is the rate at the speech signal is sampled
samples = [1,2000];
[x,Fs] = audioread('.wav',samples); 
% t = linspace(0,1/8,2000);
% x = sin(1394*pi*t) + sin(3266*pi*t);

%for NoisySpeech-16-22p5-mono-5secs snr is 2.1719
sound(x)
figure(1)
stem(x)
title('Recorded input audio signal');
xlabel('Length of the input audio signal');
ylabel('Amplitude of the input audio signal');

%Discrete cosine transform of the recorded signal
a0=dst(x); % a0 is dct values
s0=a0;
figure(2)
stem(a0)
axis([0 2000 -1 1]);
title('Discrete cosine transform of the recorded signal');
xlabel('Length of the DCT spectrum');
ylabel('Amplitude of the Dst spectrum');

% Thresholding the spectrum to make it sparse
% for i=1:1:2000;
% if a0(i,1)<=0.04 && a0(i,1)>=-0.06
%  a0(i,1)=0;
% else
%  a0(i,1)=a0(i,1);
% end
% end
% a0;
% figure(3)
% stem(a0)
% axis([0 2000 -1 1]);
% title('The Threshold spectrum');
% xlabel('The length of the threshold spectrum');
% ylabel('Amplitude of the threshold spectrum'); 

% Sparsity of the spectrum(K)and Length of the signal (N)
K=800; N=2000;

% Random measurement matrix
disp('Creating measurment matrix...');
A = randn(K,N);
Q = orth(A')';
disp('Done.');

%command to input data from the simulink
    %output = get(out.simout, 'Data')
    %stem(output)
    
% observations vector
y = Q*a0; 
figure(5)
plot(y)
title('Observation Vector');
%initial guess = min energy
x0 = Q'*y;
%solve the LP
tic
xp = l1eq_pd(x0, Q, [], y, 1e-2);
toc
figure(6)
plot(xp)
stem(xp)
axis([0 2000 -0.6 0.6]);
title(' Reconstructed Spectrum using l1-minimization');
% Inverse dicrete cosine transform of reconstructed signal (IDCT)
Xrec = idst(xp);
sound(Xrec,Fs)
figure(7)
stem(Xrec)

title('Reconstructed signal at the receiver');
xlabel('Length of the reconstructed signal using IDCT');
ylabel('Amplitude of the reconstructed signal using IDCT');
% Calculating Absolute error between the reconstructed and actual signal
%err=(max(abs(Xrec-x)))p
%stem(err);
title(' Absolute Error of Reconstructed spectrum and Threshold spectrum ');
xlabel('Length of the Maximum Absolute Error');
ylabel('Maximum Absolute error')
disp('median = ' )
display(median(s0))
disp('mean = ')
display(mean(s0))
disp('Signal to Noise Ratio (SNR) =')
display(snr(x,Xrec))

function xp = l1eq_pd(x0, A, At, b, pdtol, pdmaxiter, cgtol, cgmaxiter)
largescale = isa(A,'function_handle');
if (nargin < 5), pdtol = 1e-3; end
if (nargin < 6), pdmaxiter = 50; end
if (nargin < 7), cgtol = 1e-8; end
if (nargin < 8), cgmaxiter = 200; end
N = length(x0);
alpha = 0.01;
beta = 0.5;
mu = 10;
gradf0 = [zeros(N,1); ones(N,1)];
% starting point --- make sure that it is feasible
if (largescale)
if (norm(A(x0)-b)/norm(b) > cgtol)
 disp('Starting point infeasible; using x0 = At*inv(AAt)*y.');
 AAt = @(z) A(At(z));
 [w, cgres, cgiter] = cgsolve(AAt, b, cgtol, cgmaxiter, 0);
if (cgres > 1/2)
 disp('A*At is ill-conditioned: cannot find starting point');
 xp = x0;
return;
end
 x0 = At(w);
end
else
if (norm(A*x0-b)/norm(b) > cgtol)
 disp('Starting point infeasible; using x0 = At*inv(AAt)*y.');
 opts.POSDEF = true; opts.SYM = true;
 [w, hcond] = linsolve(A*A', b, opts);
if (hcond < 1e-14)
 disp('A*At is ill-conditioned: cannot find starting point');
 xp = x0;
return;
end
 x0 = A'*w;
end
end
x = x0;
u = (0.95)*abs(x0) + (0.10)*max(abs(x0));
% set up for the first iteration
fu1 = x - u;
fu2 = -x - u;
lamu1 = -1./fu1;
lamu2 = -1./fu2;
if (largescale)
 v = -A(lamu1-lamu2);
 Atv = At(v);
 rpri = A(x) - b;
else
 v = -A*(lamu1-lamu2);
 Atv = A'*v;
 rpri = A*x - b;
end
sdg = -(fu1'*lamu1 + fu2'*lamu2);
tau = mu*2*N/sdg;
rcent = [-lamu1.*fu1; -lamu2.*fu2] - (1/tau);
rdual = gradf0 + [lamu1-lamu2; -lamu1-lamu2] + [Atv; zeros(N,1)];
resnorm = norm([rdual; rcent; rpri]);
pditer = 0;
done = (sdg < pdtol) | (pditer >= pdmaxiter);
while (~done)

pditer = pditer + 1;

w1 = -1/tau*(-1./fu1 + 1./fu2) - Atv;
w2 = -1 - 1/tau*(1./fu1 + 1./fu2);
w3 = -rpri;

sig1 = -lamu1./fu1 - lamu2./fu2;
sig2 = lamu1./fu1 - lamu2./fu2;
sigx = sig1 - sig2.^2./sig1;

if (largescale)
 w1p = w3 - A(w1./sigx - w2.*sig2./(sigx.*sig1));
 h11pfun = @(z) -A(1./sigx.*At(z));
[dv, cgres, cgiter] = cgsolve(h11pfun, w1p, cgtol, cgmaxiter, 0);
if (cgres > 1/2)
 disp('Cannot solve system. Returning previous iterate. (See Section 4 of notes for more information.)');
 xp = x;
return
end
 dx = (w1 - w2.*sig2./sig1 - At(dv))./sigx;
 Adx = A(dx);
 Atdv = At(dv);
else
 w1p = -(w3 - A*(w1./sigx - w2.*sig2./(sigx.*sig1)));
 H11p = A*(sparse(diag(1./sigx))*A');
 opts.POSDEF = true; opts.SYM = true;
 [dv,hcond] = linsolve(H11p, w1p, opts);
if (hcond < 1e-14)
 disp('Matrix ill-conditioned. Returning previous iterate. (See Section 4 of notes for more information.)');
 xp = x;
return
end
 dx = (w1 - w2.*sig2./sig1 - A'*dv)./sigx;
 Adx = A*dx;
 Atdv = A'*dv;
end

 du = (w2 - sig2.*dx)./sig1;

 dlamu1 = (lamu1./fu1).*(-dx+du) - lamu1 - (1/tau)*1./fu1;
 dlamu2 = (lamu2./fu2).*(dx+du) - lamu2 - 1/tau*1./fu2;

 % make sure that the step is feasible: keeps lamu1,lamu2 > 0, fu1,fu2 < 0
 indp = find(dlamu1 < 0); indn = find(dlamu2 < 0);
 s = min([1; -lamu1(indp)./dlamu1(indp); -lamu2(indn)./dlamu2(indn)]);
 indp = find((dx-du) > 0); indn = find((-dx-du) > 0);
 s = (0.99)*min([s; -fu1(indp)./(dx(indp)-du(indp)); -fu2(indn)./(-dx(indn)-du(indn))]);

 % backtracking line search
 suffdec = 0;
 backiter = 0;
while (~suffdec)
 xp = x + s*dx; up = u + s*du;
 vp = v + s*dv; Atvp = Atv + s*Atdv;
 lamu1p = lamu1 + s*dlamu1; lamu2p = lamu2 + s*dlamu2; 
 fu1p = xp - up; fu2p = -xp - up;
 rdp = gradf0 + [lamu1p-lamu2p; -lamu1p-lamu2p] + [Atvp; zeros(N,1)];
 rcp = [-lamu1p.*fu1p; -lamu2p.*fu2p] - (1/tau);
 rpp = rpri + s*Adx;
 suffdec = (norm([rdp; rcp; rpp]) <= (1-alpha*s)*resnorm);
 s = beta*s;
 backiter = backiter + 1;
if (backiter > 32)
 disp('Stuck backtracking, returning last iterate. (See Section 4 of notes for moreinformation.)')
 xp = x;
return
end
end


 % next iteration
 x = xp; u = up;
 v = vp; Atv = Atvp;
 lamu1 = lamu1p; lamu2 = lamu2p;
 fu1 = fu1p; fu2 = fu2p;

 % surrogate duality gap
 sdg = -(fu1'*lamu1 + fu2'*lamu2);
 tau = mu*2*N/sdg;
 rpri = rpp;
 rcent = [-lamu1.*fu1; -lamu2.*fu2] - (1/tau);
 rdual = gradf0 + [lamu1-lamu2; -lamu1-lamu2] + [Atv; zeros(N,1)];
 resnorm = norm([rdual; rcent; rpri]);
 done = (sdg < pdtol) | (pditer >= pdmaxiter);
 fprintf('Iteration = %d, tau = %8.3e, Primal = %8.3e, PDGap = %8.3e, Dual res = %8.3e, Primal res = %8.3e\n',...
     pditer, tau, sum(u), sdg, norm(rdual), norm(rpri));
if(largescale)
 fprintf('CG Res = %8.3e, CG Iter = %d\n', cgres, cgiter);
else
 fprintf('H11p condition number = %8.3e\n', hcond);
end
end
end