function f = lagrauge_barycentric(xi, fi, x)
    n = length(xi);
    w = ones(1, n);
    
    for j = 1:n
        w(j) = prod(xi(j) - xi([1:j-1, j+1:n]));
    end
    
    w = 1./w;
    numerator = zeros(size(x));
    denominator = numerator;
    exact = numerator;
    
    for j = 1:n
        xdiff = x - xi(j);
        term = w(j)./xdiff;
        numerator = numerator + term * fi(j);
        denominator = denominator + term;
        exact(xdiff == 0) = j;
    end
    
    f = numerator./denominator;
    k = find(exact);
    f(k) = fi(exact(k));
end
