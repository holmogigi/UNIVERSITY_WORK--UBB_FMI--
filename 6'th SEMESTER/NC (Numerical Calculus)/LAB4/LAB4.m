% 1. a)
x = [0,1,2];
f = [1,1/2,1/3];
divided_diff(x, f)

%1. b)
x = [0,1,2];
f = [1,1/2,1/3];
df = -1./(1+x).^2;
[z, t] = divided_diff2(x, f, df)

%1. c)
x = linspace(1,2,11);
f = 1./(1+x);
df = -1./(1+x).^2;
divided_diff(x, f)
[z, t] = divided_diff2(x, f, df)

%2. a)
x = [-2,-1,0,1,2,3,4];
f = [-5,1,1,1,7,25,60];
divided_diff(x, f)

%2. b)
forward_diff(f)
    
%2. c)
backward_diff(f)
