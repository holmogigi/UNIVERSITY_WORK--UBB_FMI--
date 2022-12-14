function [m1, m2]=CI(x,sigma,alpha)
  xmean=mean(x);
  n=length(x);
  m1=xmean-sigma/sqrt(n)*norminv(1-alpha/2);
  m2=xmean+sigma/sqrt(n)*norminv(1-alpha/2);
