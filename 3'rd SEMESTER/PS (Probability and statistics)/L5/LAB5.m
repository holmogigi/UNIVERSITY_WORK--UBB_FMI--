pkg load statistics

x=[7 7 4 5 9 9 ...
4 12 8 1 8 7 ...
3 13 2 1 17 7 ...
12 5 6 2 1 13 ...
14 10 2 4 9 11 ...
3 5 12 6 10 7];

#B

#1
#a)
[m1,m2]=CI(x, 5, 0.05)
#b)
[m3,m4]=CI2(x, 0.05)
#c)
[m5, m6]=CI3(x,0.05)

#2
#a)
clear ztest
sig = 5;
n = 9;
[h, p, ci, ztst] = ztest(x, n, sig, 'alpha', 0.05, 'tail', 'left');
RR = [-inf, norminv(0.05)];
if h==1
    fprintf('\nthe null hypotesis is rejected');
else
    fprintf('\n.... not rejected');
endif
fprintf('\nthe reg. region = [%1.2f, %1.2f]', RR);
fprintf('\nthe value of the statistic = %1.2f', ztst);
fprintf('\nthe p-value = %1.2f', p);

#b)
n = 5.5;
[h, p, ci, ttst] = ttest(x, n, 'alpha', 0.05, 'tail', 'right')
RR = [tinv(1-(0.05/2), ttst.df), inf]

