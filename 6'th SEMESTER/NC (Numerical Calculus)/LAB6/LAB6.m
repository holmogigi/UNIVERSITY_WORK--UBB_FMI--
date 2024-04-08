% check if lagrauge_init is correct
lagrauge_init([1,2,3], [1,4,9], 4);
lagrauge_init([1,2,3], [1,4,9], [5,4]);

% Ex 1.
% a). 
xi = linspace(-2,4,10);
fi = (xi + 1)./(3*xi.^2 + 2*xi+1);

x = linspace(-2,4,500);
f = (x + 1)./(3*x.^2 + 2*x+1);
L9f = lagrauge_init(xi, fi, x);

% b).
%plot(x, f, x, L9f, '-p')

% c).
%plot(x, abs(f - L9f), '-r')
max(abs(f - L9f));

% d).
x = 1/2;
f = (x + 1)./(3*x.^2 + 2*x+1);
L9f = lagrauge_init(xi, fi, x);
max(abs(f - L9f));

% check if lagrauge_barycentric is correct
lagrauge_barycentric([1,2,3], [1,4,9], 5);
lagrauge_barycentric([1,2,3], [1,4,9], 2);
lagrauge_barycentric([1,2,3], [1,4,9], 4);

% Ex 2.
xi = 1980:10:2020;
fi = [4451, 5287, 6090, 6970, 7821];
lagrauge_barycentric(xi, fi, [2005, 2024]);

% Ex 3.
xi = [100, 121, 144];
fi = [10, 11, 12];
lagrauge_barycentric(xi,fi, [118])
