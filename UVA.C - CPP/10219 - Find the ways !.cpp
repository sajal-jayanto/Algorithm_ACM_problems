#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>


int main()
{
    unsigned long long n,r,i;
    long double sum;
    while(scanf("%llu %llu",&n,&r) == 2)
    {
        sum = 0.00;
        for(i = n ; i > n - r ; i--) sum = sum + log10(i);
        for(i = r ; i > 0 ; i--) sum = sum - log10(i);
        n = floor(sum) + 1;
        printf("%llu\n",n);
    }
    return 0;
}

