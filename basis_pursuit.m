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
%       
epsilon = 0    
x0 =  Basis_Pursuit( b,phi,epsilon )
rec = idct(x0) 

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

%snr = 2.64 - basis pursuit


function [ s_BP ] = Basis_Pursuit( b,phi,epsilon )

%Basis Pursuit Algorithm (BP)
%   Inputs    
%       y     : measured vector
%       Theta : Sensing matrix
%       epsilon : tolerance for approximation between successive solutions.
%   Output
%       s_BP  : Solution found by the algorithm
%By MohammadReza Jabbari-Email: Mo.re.jabbari@gmail.com.
mode = 2;           %Default Mode ("epsilon" is detremined)
N = size(phi,2);  %Signal dimension
if nargin <3,  mode = 1;end
if mode==1    %"epsilon" isn't detremined
    cvx_begin quiet
    variables s(N) epsilon
        minimize(norm(s,1)+10*epsilon)
        subject to
        norm(b-phi*s,2)<=epsilon;
        epsilon>=0;
    cvx_end
elseif mode==2 %"epsilon" is determined 
    cvx_begin quiet
    variables s(N) 
        minimize(norm(s,1))
        subject to
        norm(b-phi*s,2)<=epsilon;
    cvx_end
end
s_BP = s;
end



% function [x0] = OMP (K,b,z)
% Res = b.' ;
% [m,n] = size (z) ;
% Q = zeros (m,K) ;
% R = zeros (K,K) ;
% Rinv = zeros (K,K) ;
% w = zeros (m,K) ;
% x0 = zeros (1,n) ;
% for J = 1 : K
%     
%     %Index Search
%     [V ,kkk] = max(abs(z'*Res')) ;
%     kk (J) = kkk ;
%     
%     %Residual Update
%     w (:,J) = z (:,kk (J)) ;
%     for I = 1 : J-1
%         if (J-1 ~= 0)
%             R (I,J) = Q (:,I)' * w (:,J) ;
%             w (:,J) = w (:,J) - R (I,J) * Q (:,I) ;
%         end
%     end
%     R (J,J) = norm (w (:,J)) ;
%     Q (:,J) = w (:,J) / R (J,J) ;
%     b = b - (Q (:,J) * Q (:,J)' * b) ;
%   
% end
% % %Least Squares
% % for J = 1 : K
% %     Rinv (J,J) = 1 / R (J,J) ;
% %     if (J-1 ~= 0)
% %         for I = 1 : J-1
% %             Rinv (I,J) = -Rinv (J,J) * (Rinv (I,1:J-1) * R (1:J-1,J)) ;
% %         end
% %     end
% % end
% % xx = Rinv * Q' * b ;
% % for I = 1 : K
% %     x0 (kk (I)) = xx (I) ;
% % end
% end