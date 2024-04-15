% 1)
xi = [0, 1, 2];
fi = 1./(1+xi);
xx = linspace(0, 2, 100);
d = dividff(xi, fi);
Lf = newton_int(d, xi, xx);
plot(xx, Lf);

dfi = -1./(1+xi).^2;
[zi, d2] = dividffdouble(xi, fi, dfi);
Hf = newton_int(d2, zi, xx);
hold on;
plot(xx, Hf);

% 2)
xi = [0, 3, 5, 8, 13];
fi = [0, 225, 383, 623, 993];
dfi = [0, 77, 80, 74, 72];
t=10;
[zi, d2] = dividffdouble(xi, fi, dfi);
distance = newton_int(d2, zi, t)

d = dividff(xi, dfi);
speed = newton_int(d, xi, t)

d3 = dividff(fi, dfi);
speed2 = newton_int(d3, fi, distance)
