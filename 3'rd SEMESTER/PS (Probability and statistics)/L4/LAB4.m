pkg load statistics

#1.
rand
randn

#2.
#a)
clear X
p = input("Bernoulli Distribution Bern: ");
n = input("Nr of simulation: ");
for i=1:n
  r=rand;
  X(i)= r<p;
end
U_X=unique(X);
u_X=hist(X, length(U_X))
u_X/n


#b)
clear X
p = input("Bernoulli Distribution Bern: ");
N = input("Nr of simulation: ");
n = input("Nr of trials:");
r=rand(n, N);
X=sum(r<p);
U_X=unique(X);
u_X=hist(X, length(U_X))
k=0:n;
p_k=binopdf(k,n,p)
clf
plot(k, p_k, 'o', U_X, u_X/N, '*')


#c)
clear X
p=input("p=");
N=input("Nr of simulations: ")
for i=1:N
  X(i)=0;
  while rand >= p
    X(i)=X(i)+1;
  endwhile
end
k=0:20;
p_k=geopdf(k, p)
U_X=unique(X);
u_X=hist(X, length(U_X))
clf
plot(k, p_k, 'o', U_X, u_X/N, '*')


#d)
clear X
clear Y
p=input("p= ");
N=input("Nr of simulations: ");
n=input("Nr of succeces: ");
for i=1:N
  for j=1:n
    X(j)=0;
    while rand >= p
      X(j)=X(j)+1;
    endwhile
    Y(i)=sum(X);
  endfor
end
U_Y=unique(Y);
n_Y=hist(Y, length(U_Y));
k=0:150;
p_k=nbinpdf(k,n,p);
plot(k, p_k, 'o', U_Y, n_Y/N, '*')
