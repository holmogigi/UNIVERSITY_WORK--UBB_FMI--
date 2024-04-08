syms x;
xi = [0,1/3,1/2,1];
fi = cos(pi*xi);
dd = dividff(xi, fi); 
Nf = newton_int(dd, xi, x)

f=cos(pi*x);
ezplot(f, [0,1]);
hold on
ezplot(Nf, [0,1]);

vpa(subs(Nf,x,1/5))

x = 1/5;
Nf = newton_int(dd, xi, x)
cos(pi/5)

xi = -4:4;
fi = 2.^xi;
aitken(xi,fi,1/2)
sqrt(2)


xi = [1000,1010,1020,1030,1040,1050];
fi = [3.0000000, 3.0043214, 3.0086002, 3.0128372, 3.0170333, 3.0211893];
dd = dividff(xi,fi);
newton_int(dd, xi, 1001:1009)
log10(1001:1009)
