function td = dividff(x, f)
    n = lenght(x);
    td = zeros(n);
    td(:,1) = f';
    for j=2:n
        td(1:n-j+1, j) = diff(td(1:n-j+2, j-1))./(x(j:n)-x(1:n-j+1))';
    end
end
