%1.a)
x = [0, 1, 2];
f = [1, 1/2, 1/3];
dividff(x,f)

%1.b)
x = [0, 1, 2];
f = [1, 1/2, 1/3];
fd = -1./(1+x).^2;
[z, td] = dividffdouble(x, f, fd)

%1.c)
x = linspace(1, 2, 11);
f = 1./(1+x);
fd = -1./(1+x).^2;
dividff(x, f)
[z, td] = dividffdouble(x, f, fd)

%2.a)
x = [-2, -1, 0, 1, 2, 3, 4];
f = [-5, 1, 1, 1, 7, 25, 60];
dividff(x,f)

%2.b)
for_diff(f)

%2.c)
for_diffback(f)
