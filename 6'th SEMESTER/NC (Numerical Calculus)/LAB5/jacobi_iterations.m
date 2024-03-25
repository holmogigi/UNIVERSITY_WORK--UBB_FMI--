function [x, nit] = jacobi_iterations(A, b, x0, maxit, epsilon)
    N = -triu(A, 1);
    %M = diag(diag(A));
    M = tril(A);
    %N = M - A;
    T = inv(M)*N;
    c = inv(M)*b;
    alfa = norm(T, inf);
    for nit = 1:maxit
        x = T*x0+c;
        if norm(x-x0, inf) < epsilon* (1-alfa)/alfa
            return
        end
        x0=x;
    end
end
