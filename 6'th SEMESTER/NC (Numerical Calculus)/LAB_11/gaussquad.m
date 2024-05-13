function [I, g_nodes, g_coeff] = gaussquad(f, n, g_type)
    alpha = zeros(n,1);
    switch g_type
        case 1 % legendre
            beta = [2, (4-[1:n-1].^(-2)).^(-1)];
        case 2 % chebyshev 1
            beta = [2, (4-[1:n-1].^(-2)).^(-1)];
        case 3 % chebyshev 2
            beta = [pi/2, ones(1, n-1)*1/4];
        case 4 % laguerre
            beta = [2, (4-[1:n-1].^(-2)).^(-1)];
        case 5 % hermite
            beta = [2, (4-[1:n-1].^(-2)).^(-1)];
    end
        J = diag(alpha) + diag (sqrt(beta(2:n)), -1) + diag (sqrt(beta(2:n)), 1);
        [v, d] =  eig(J);
        g_nodes = diag(d);
        g_coeff = beta(1)*v(1,:).^2;
        I = g_coeff*f(g_nodes);
end
