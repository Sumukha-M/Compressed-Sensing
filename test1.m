clc
close all;
clear all;

Fs=5000;
load gong;

%sound(y)
s = y;

%s=audioread('a1.wav');
figure(1);
stem(s);
title('Input speech signal');
xlabel('Length of the input speech signal');
ylabel('Amplitude of the input speech signal');
l_s = length(s); 


% Wavelet transform of input signal
[cA1,cD1] = dwt(s,'db1');

%To extract the Level-1 Approximation and Detail coefficient
A1 = idwt(cA1,[],'db1',l_s);
D1 = idwt([],cD1,'db1',l_s);
figure(2)
subplot(1,2,1); plot(A1); title('Approximation A1')
subplot(1,2,2); plot(D1); title('Detail D1')


%Inverse Wavelet transform of Approximation and detail coefficient
A0 = idwt(A1,D1,'db1',l_s);

sound(A0,Fs)
%sound(A0)

figure(3)
stem(A0)
title('Recontructed speech signal');
xlabel('Length of the reconstructed speech signal');
ylabel('Amplitude of the reconstructed speech signal');
err = max(abs(s-A0))