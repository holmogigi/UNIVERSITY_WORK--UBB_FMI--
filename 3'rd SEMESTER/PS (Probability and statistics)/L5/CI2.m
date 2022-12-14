function [m1, m2]=CI2(x,alpha)
  xmean=mean(x);
  n=length(x);
  s=std(x);
  m1=xmean-s/sqrt(n)*tinv(1-alpha/2,n-1);
  m2=xmean+s/sqrt(n)*tinv(1-alpha/2,n-1);
