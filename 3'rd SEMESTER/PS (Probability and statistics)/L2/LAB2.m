#Plot the graphs of the pdf and the cdf of a random variableXhaving a binomial distribution of parameters n and p(given by the user).

n=input("Nr of trials: ");
p=input("Prob of succ: ");
x=0:n;
px=binopdf(x,n,p);
plot(x,px);

hold on;

xx=0:1.1:n;
fx=binocdf(xx,n,p);
plot(xx,fx);



#A coin is tossed 3 times. LetXdenote the number of heads that appear.
#c)Find P(X=0), P(X!=1)
#d)Find P(X<=2), P(X<2)
#e)Find P(X>=1), P(X>1)

#P(X=0)
p1=binopdf(0,3,0.5);
fprintf('p(X=0)=%1.3f\n',p1);

#P(X!=1)
p2=1-binopdf(1,3,0.5);
fprintf('p(X!=1)=%1.3f\n',p2);

#P(X<=2)
p3=binocdf(2,3,0.5);
fprintf('p(X<=2)=%1.3f\n', p3);

#P(X<2)
p4=binocdf(1,3,0.5);
fprintf('p(X<2)=%1.3f\n', p4);

#P(X>=1)
p5=1-cdf('Binomial',0,3,0.5);
fprintf('p(X>=1)=%1.3f\n',p5);

#P(X>1)
p6=1-cdf('Binomial',1,3,0.5);
fprintf('p(X>1)=%1.3f\n',p6);


#f)Write code that simulates 3 coin tosses and computes the value of the variable X
N=10;
C=rand(3,N)
D=(C<0.5);
X=sum(D);
clf;
hist(X);
