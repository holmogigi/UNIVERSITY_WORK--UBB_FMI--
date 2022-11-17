#include <stdio.h>

int compare_max(int a, int b);
void main()
{
    freopen("max.txt", "w", stdout); // writing the result into the max.txt file 
    int n, a, b, c, i, maxi = -1000000;
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);
    maxi = compare_max(a, b);
    for (i = 1; i < n - 1; i += 1)
    {
        scanf("%d", &c);
        maxi = compare_max(maxi, c);   // comparation function here
    }
    printf("%x", maxi);
}
