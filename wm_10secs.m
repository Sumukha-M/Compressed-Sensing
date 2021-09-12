clc;
clear all;
close all;
%Fs Hz (samples per second) is the rate at the speech signal is sampled
samples = [1,2000];
[x,Fs] = audioread('WashingMachine-16-44p1-stereo-10secs.wav',samples);
figure(1)
stem(x)
title('Recorded input audio signal');
xlabel('Length of the input audio signal');
ylabel('Amplitude of the input audio signal');
%Discrete cosine transform of the recorded signal
a0=dct(x);
s0=a0;
figure(2)
stem(a0)
axis([0 2000 -1 1]);
title('Discrete cosine transform of the recorded signal');
xlabel('Length of the DCT spectrum');
ylabel('Amplitude of the DCT spectrum');
% Thresholding the spectrum to make it sparse
for i=1:1:2000;
if a0(i,1)<=0.04 && a0(i,1)>=-0.06
 a0(i,1)=0;
else
 a0(i,1)=a0(i,1);
end
end
a0;
figure(3)
stem(a0)
axis([0 2000 -1 1]);
title('The Threshold spectrum');
xlabel('The length of the threshold spectrum');
ylabel('Amplitude of the threshold spectrum'); 
% Sparsity of the spectrum(K)and Length of the signal (N)
K=800;
N=2000;
% Random measurement matrix
disp('Creating measurment matrix...');
A = randn(K,N);
A
Q = orth(A')';
figure(4)
imagesc(Q)
colorbar;
colormap('lines');
title('Random Measurement matrix');
disp('Done.');
% observations vector
y = Q*a0; 
figure(5)
plot(y)
title('Observation Vector');
%initial guess = min energy
x0 = Q'*y;
%solve the LP
y = Q*a0;
figure(5)
plot(y)
title('Observation Vector');
%initial guess = min energy
L1=vecnorm(y,1);

%output = get(out.simout, 'Data')
%stem(output)

