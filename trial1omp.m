clc; clear; close all;

samples = [1,2000];
[x,Fs] = audioread('Click-16-44p1-mono-0.2secs.wav',samples); % Fs is Sampling Rate at which the speech signal is sampled

% cvx NoisySpeech-16-22p5-mono-5secs snr value is 1.5766

disp('Analyzing input audio signal...');
sound(x)
%x=input audio samples
%Discrete cosine transform of the recorded signal
a0=dct(x);

% Sparsity of the spectrum(K)and Length of the signal (N)
K=800;  %K= randomly picked samples from N
N=2000; %N= No. of samples taken from input signal

% Random measurement matrix
disp('Creating measurment matrix...');
A = randn(K,N);     %A= random matrix  
phi = orth(A')';      %phi= sensing matrix
disp('Done.');

b = phi*x;     %compressed signal (compressive measurements)(b vector) 
disp('Compression Ratio:');
display(N/K);

psi=dct(eye(N,N)); %psi matrix (change to dft)
z=phi*psi; %compressed measurements

inv = conj(psi/N);
%cvx package used
% cvx_begin
%     variable x0(N);
%     minimize(norm(x0,1));
%     subject to
%         z*x0==b;
%       cvx_end
      

 xomp= OMP(K, b, z);   

rec = idct(xomp) 

sound(rec)

display('........SNR value is.....');
display(snr(x,rec))      %snr output is in db...greater than 0 
                         %values indicates more signal than noise

figure(4)
stem(rec);
title('reconstructed signal');
%plotting of all inputs and outputs
figure(3)
stem(b)
title('Compressive Measurement matrix');

figure(2)
stem(a0)
axis([0 2000 -1 1]);
title('Discrete cosine transform of the recorded signal');
xlabel('Length of the DCT spectrum');
ylabel('Amplitude of the DCT spectrum');

figure(1)
stem(x)
title('Recorded input audio signal');
xlabel('Length of the input audio signal');
ylabel('Amplitude of the input audio signal');






function [x0] = OMP (K,b,z)
Res = b' ;
[m,n] = size (z) ;
Q = zeros (m,K) ;
R = zeros (K,K) ;
Rinv = zeros (K,K) ;
w = zeros (m,K) ;
x0 = zeros (1,n) ;
for J = 1 : K
    
    %Index Search
    [V ,kkk] = max(abs(z'*b)) ;
    kk (J) = kkk ;
    
    %Residual Update
    w (:,J) = z (:,kk (J)) ;
    for I = 1 : J-1
        if (J-1 ~= 0)
            R (I,J) = Q (:,I)' * w (:,J) ;
            w (:,J) = w (:,J) - R (I,J) * Q (:,I) ;
        end
    end
    R (J,J) = norm (w (:,J)) ;
    Q (:,J) = w (:,J) / R (J,J) ;
    Res = b - (Q (:,J) * Q (:,J)' * b) ;
  
end
%Least Squares
for J = 1 : K
    Rinv (J,J) = 1 / R (J,J) ;
    if (J-1 ~= 0)
        for I = 1 : J-1
            Rinv (I,J) = -Rinv (J,J) * (Rinv (I,1:J-1) * R (1:J-1,J)) ;
        end
    end
end
xx = Rinv * Q' * b ;
for I = 1 : K
    x0 (kk (I)) = xx (I) ;
end
end
% function  x0 = algo_omp(k, A, b)
%     xbeg = zeros(size(A,2),1);
%     support=[];
%     temp=b;
%     count = 1;
%     while count < k+1
%         ST = abs(A' * temp);
%         [a, b] = max(ST);
%         support = [support b];
%         xfinal = A(:, support)\b;
%         temp = b-A(:,support) * xfinal;
%         count = count + 1;
%     end
%     x0 = xbeg;
%     t = support';
%     xt = xfinal;
% end

%
%plot(x,rec)
%stem(x,rec)
%t=1:100;
%plot(t,x,t,rec)

%cvx-mae:0.0458,mse:0.01,sse:19.9866
%l1function-mae:0.0638,mse:0.0066,sse:13.1204
 

