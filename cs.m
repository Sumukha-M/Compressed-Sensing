n = 4096;
t = linspace(0,1,n);
x = cos(2*pi*500*t);
xn = fft(x);

p = 128;
perm = round(rand(p,1)*n);
y = x(perm);

psi = dct(eye(n,n));
theta = psi(perm, :);

s = cosamp(theta,y',10,0,10);
xrecon = idct(s);

subplot(4,1,1);
plot(n,x);
subplot(4,1,2);
plot(n,y);
subplot(4,1,3);
plot(n,s);
subplot(4,1,4);
plot(n,xrecon);
