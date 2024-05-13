vpa(pi*sqrt(3)/9, 6)
[I, nfev] = ronberg(@(x)1./(2+sin(x)), 0, pi/2, 10^-5, 100)


gaussquad(@(x)x.^2+1./(x.^2+1), 2, 3) * 2


integral(@(x) exp(cos(x)), 0, pi/4)
gaussquad(@(x) exp(cos(x)), 5, 1)


gaussquad(@(x)exp(-x).^2.*cos(x), 6, 1)
