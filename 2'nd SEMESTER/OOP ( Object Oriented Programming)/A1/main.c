#include <stdio.h>

// Function that prints the menu in the loop
void print_menu()
{
    printf("\n");
    printf("               MENU");
    printf("\n");
    printf("Press '1' for the first(8.a) problem statement");
    printf("\n");
    printf("Press '2' for the second(8.b) problem statement");
    printf("\n");
    printf("Press '3' for the third(9.a) problem statement");
    printf("\n");
    printf("Press '0' to close the application");
    printf("\n");
    printf("Choose an option:");
}

// Function that prints the subsequence from the first index to the last index
void print_subsequence(int v[],int first_index,int second_index)
{
    for(int i=first_index;i<second_index;i++)
    {
        printf("%d", v[i]);
        printf(" ");
    }
}

// Function that prints the error messaage
void error_subsequence()
{
    printf("There are no such subsequences in the vector!");
}

// Function that solves the second problem. We compare 2 consecutive numbers in the vector. If they meet the criteria
// we keep on going and searching to see how many elements in the vector are good. When the criteria isn't met anymore
// the loop ends and the if statement compares the length of this sequence with the length of the max one at that time.
// If it's greater the max updates, and we define 2 variables, the beginning index of the subsequence and the end. If
// no such subsequence is found a message is printed.
int *statement_2(int v[],int n)
{
    int ok,i,j,max=-1,k,first_index,second_index,good=0;
    for (i=0;i<n-1;i++)
    {
        if((v[i]>0 && v[i+1]<0) || (v[i]<0 && v[i+1]>0))
        {
            good=1;
            k=1;
            j=i+1;
            ok=1;
            while (j<n && ok)
            {
                if((v[j]>0 && v[j+1]<0) || (v[j]<0 && v[j+1]>0))
                    k++;
                else
                    ok=0;
                j++;
            }
            if (k>max)
            {
                max=k;
                first_index=i;
                second_index=j;
            }
        }
    }
    static int out[3];
    out[0]=good;
    out[1]=first_index;
    out[2]=second_index;
    return out;
}

// Function that recives a pointer and prints an error ot the subsequence
void check_statement_2(int *p, int v[])
{
    if (*(p+0)==1)
        print_subsequence(v,*(p+1),*(p+2));
    else
        error_subsequence();
}

// Function that solves the first problem. Time complexity: O(log n). This algo (Binary Exponentiation) will take a
// divide and conquer approach on the problem. The theory is that (x^n):
// if n=0=>x^n=1
// if n%2==0 (n even) => x^n= (x^((n-1)/2))^2 * x
// if n%2!=0 (n is odd) => x^n= (x^(n/2))^2
// In conclusion the function will call itself until n=1 and check whether n is odd or even to use the right formula
float statement_1(int n,float x)
{
    float log;
    if (n==0)
        return 1;
    if (n%2==1)
    {
        log= statement_1(n-1,x);
        log=log*x;
        return log;
    }
    else
    {
        log= statement_1(n/2,x);
        return log*log;
    }
}

// Function that solves the third problem statement. The algo starts from 2 and checks if the number divides with prime
// numbers up until prime*prime is greater than the number inputted.
void statement_3(int n)
{
    int d=2,p;
    while (n>1)
    {
        p=0;
        while (n%d==0)
        {
            p++;
            n=n/d;
        }
        if (p)
        {
            printf("%d", d);
            printf("^");
            printf("%d", p);
            printf("\n");
        }
        d++;
        if (n>1 && d*d>n)
            d=n;
    }
}

// Main function
int main()
{
    int option,ok=1;
    while (ok)
    {
        print_menu();
        scanf("%d", &option);
        printf("\n");
        if (option == 1)
        {
            int n;
            float x;
            printf(" x= ");
            scanf("%f", &x);
            printf("n= ");
            scanf("%d", &n);
            printf("%f",statement_1(n,x));
            printf("\n");
        }
        else if (option == 2)
        {
            int n,*p;
            printf(" n= ");
            scanf("%d", &n);
            int v[n];
            printf("Vector elements: ");
            for (int i=0;i<n;i++)
                scanf("%d", &v[i]);
            p = statement_2(v,n);
            check_statement_2(p,v);
            printf("\n");
        }
        else if(option==3)
        {
            int n;
            printf("n=");
            scanf("%d", &n);
            statement_3(n);
        }
        else if (option == 0)
        {
            ok=0;
            printf("           Exiting...");
        }
        else
        {
            printf("!ERROR! The input is invalid!");
            printf("\n");
        }
    }
    return 0;
}