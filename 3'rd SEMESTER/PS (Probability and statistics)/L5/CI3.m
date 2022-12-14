function [m1, m2]=CI3(x,alpha)
  n=length(x);
  ssquared = var(x);
  xsquaredalfa = chi2inv(alpha/2, n-1);
  xsquaredalfac = chi2inv(1-alpha/2, n-1);
  m1 =  sqrt((n-1)* ssquared / xsquaredalfac);
  m2 = sqrt((n-1)* ssquared /xsquaredalfa);
