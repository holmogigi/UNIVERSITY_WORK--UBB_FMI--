/*
p1 (max of 3 numbers)

~
let a,b,c : int;
in(a);
in(b);
in(c);
if (a>b and a>c);
{
    out(a);
    stop;
}
if (b>a and b>c);
{
    out(b);
    stop;
}
if (c>a and c>b);
{
    out(c);
    stop;
}
~ 

 */


/*
p2 (gcd 2 numbers)

~
let a,b,min : int;
in(a);
in(b);
if(a>b);
{
    min=b;
}
else;
{
    min=a;
}
while (min>0);
{
    if(a%min==0 and b%min==0);
    {
        break;
    }
    else;
    {
        min--;
    }
}
out(min);
~ 

 */


/*
p3 (sum of first n numbers)

~
let n,sum : int;
in(n);
list l(n) : int;
let i : int;
i=1;
while(i<n);
{
    in(l[i]);
    sum=sum+l[i];
    i++;
}
out(sum);
~ 

*/


/*
p1err (sum of first n numbers with 2 lexical errors)
~
let n,sum : irt;
in(n);
let i : int;
i=1;
while(i<=n);
{
    sum=sum+i;
    i++;
}
out(sum);
~ 

*/