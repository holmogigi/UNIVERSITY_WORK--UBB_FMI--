syms x
f = exp(x);
taylor(f,x,0,'order',1);

% 1.

Tf1 = taylor(f,x,0,'order',2);
Tf2 = taylor(f,x,0,'order',3);
Tf3 = taylor(f,x,0,'order',4);
Tf4 = taylor(f,x,0,'order',5);

ezplot(Tf1, [-3,3])
hold on
ezplot(Tf2, [-3,3])
hold on
ezplot(Tf3, [-3,3])
hold on
ezplot(Tf4, [-3,3])

exp(1);
vpa(exp(1),7)

a = subs(Tf4, x, 1);
vpa(a, 6)
n = 20;
for i=2:n
    Tf = taylor(f,x,0,'order',i);
    a = subs (Tf,x,1); i
    vpa(a, 7)
end

% 2.

Tf3 = taylor(f,x,0,'order',4);
Tf5 = taylor(f,x,0,'order',6);

ezplot(Tf3, [-pi,pi])
hold on
ezplot(Tf5, [-pi,pi])
hold on
ezplot(f, [-pi, pi])
hold on

f2 = sin(x);
n = 10;
for i = 2:n
    Tf = taylor(f2,x,0,'order',i); 
    a = subs (Tf,x,pi/5); i
    vpa (a, 5)
end

f2 = sin(x);
n = 10;
for i = 2:n
    Tf = taylor(f2,x,0,'order',i); 
    a = subs (Tf,x,(-1)*pi/3); i
    vpa (a, 5)
end

% 3.

f = log(1+x);
Tf1 = taylor(f,x,0,'Order',2);
Tf4 = taylor(f,x,0,'Order',5);

ezplot(Tf1,[-0.9,1]);
hold on;
ezplot(Tf4,[-0.9,1]);
hold on;

n = 30;
for i = 2:n
    Tf = taylor(f,x,0,'Order',i);
    a = subs(Tf,x,log(2)); i
    vpa(a,5)
end

f1 = log(1-x);
n = 30;
for i = 2:n
    Tf = taylor(f1,x,0,'Order',i);
    a = subs(Tf,x,log(2)); i
    vpa(a,5)
end
