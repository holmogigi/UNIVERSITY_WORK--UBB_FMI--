% 1.
[A, b] = square_matrix(1000);
maxit = 1000;
epsilon = 1/100000;
x0 = zeros(size(b));
[x, nit] = jacobi_iterations(A, b, x0, maxit, epsilon)
[x, nit] = gaussian_iterations(A, b, x0, maxit, epsilon)

% 2.
A = [10,7,8,7; 7,5,6,5; 8,6,10,9; 7,5,9,10];
b = [32, 23, 33, 31];
Ai = [10,7,8.1,7.2; 7.8,5.04,6,5; 8,5.98,9.89,9; 6.99,4.99,9,9.98];
bi = [32.1, 22.9, 33.1, 30.9];

%2.a)
resA = inv(A)*b'

%2.b)
resB = inv(A)*bi'
err_in = norm(bi-b)
err_out = norm(resB - resA/norm(A))

%2.c)
resC = inv(Ai)*b'
err_in = norm (Ai-A)/norm(A)
err_out = norm(resC - resA)/norm(resA)
