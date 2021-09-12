


% Random measurement matrix
function b = codeconv() 
%#codegen
t = linspace(0,1/8,2000); 
x = sin(1394*pi*t) + sin(3266*pi*t); 
K=800;
N=2000;
% disp('Creating measurment matrix...');
A = randn(K,N);     %A= random matrix  
Q = orth(A')';
     %phi= sensing matrix
% disp('Done.');

b = Q*x';     %compressed signal (compressive measurements)(b vector) 
% disp('Compression Ratio:');
% display(N/K);
end