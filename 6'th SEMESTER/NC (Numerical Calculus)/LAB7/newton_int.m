function f=newton_int(dd, xi, x)
    for j=1:length(x)
        u = x(j) - xi;
        f(j) = [1,cumprod(u(1:end-1))] * dd(1,:)';
    end
end
