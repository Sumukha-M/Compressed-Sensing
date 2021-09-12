function [ s_hat ] = OMP(x,A,q)
[N,K] = size(A);
s_hat= zeros(K,1);
r=x;
T=[];
for ii = 1:q
    g= A'*r;
    for b3=1:K
        f(b3)=abs(g(b3))/norm(A(:,b3));
    end
    jj = find(f == max(f));
    T = union(T,jj);
    s_hat(T)=pinv(A(:,T)) * x;  %%coeffecient update
    r=x-A*s_hat;   %%residu update
end



