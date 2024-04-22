xi= -2:4;
fi = (xi+1)./(3*xi.^2+2*xi+1);
dfi = -(3*xi.^2+6*xi+1)./(3*xi.^2+2*xi+1).^2;

xx=linspace(-2,4);
f = (xx+1)./(3*xx.^2+2*xx+1);
%plot(xx, f);
hold on

d = dividff(xi, fi);
%plot(xx,newton_int(d,xi,xx));

[zi, d2] = dividffdouble(xi, fi, dfi);
%plot(xx,newton_int(d2,zi,xx));

S = spline(xi,fi,xx);
%plot(xx, S);


xx = linspace(-1, 3/2);
xi = [-1,-1/2,0,1/2,1,3/2];
fi = xi.*sin(pi*xi);
dfi = sin(pi*xi)+ sin(pi*xi) + pi*xi.*cos(pi*xi);
S = spline(xi,fi,xx);
%plot(xx,S);

fci = [pi, fi, -1];
S2 =  spline(xi,fci,xx);
%plot(xx,S2);

fp = pchip(xi,fi,xx);
%plot(xx,fp);


xi = [0.5, 1.5, 2, 3, 3.5, 4.5, 5, 6, 7, 8];
fi = [5, 5.8, 5.8, 6.8, 6.9, 7.6, 7.8, 8.2, 9.2, 9.9];
scatter(xi, fi);
%plot(xi, fi, 'o');

p = polyfit(xi,fi,1);
xx = linspace(0.5, 8);
%plot(xx, polyval(p, xx));

%norm(fi-polyval(p,xi))
%polyval(p, 4)
