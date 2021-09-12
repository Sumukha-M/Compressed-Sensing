clc;
close all;
clear all;

% load chirp;
% yl = length(y)
% 
% p = 410;
% perm = round(rand(p,1)*yl);
% z = y(perm);

% output = get(out.simout, 'Data')

load clown
image(X);
figure(1)
stem(0:200,X)
title('Recorded input audio signal');
xlabel('Length of the input audio signal');
ylabel('Amplitude of the input audio signal');
%Discrete cosine transform of the recorded signal
a0=dct(X);
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
A = orth(A')';
figure(4)
imagesc(A)
colorbar;
colormap('lines');
title('Random Measurement matrix');
disp('Done.');
% observations vector
y = A*a0; 
figure(5)
plot(y)
title('Observation Vector');
%initial guess = min energy
x0 = A'*y;
%solve the LP
y = A*a0;
figure(5)
plot(y)
title('Observation Vector');
%initial guess = min energy
L1=vecnorm(y,1);
