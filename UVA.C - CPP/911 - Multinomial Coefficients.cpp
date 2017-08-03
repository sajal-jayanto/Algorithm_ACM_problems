#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
unsigned long long nCr(int , int);

int main()
{
    int n;
    int t,r;
    unsigned long long sum;
    while(scanf("%d",&n) == 1)
    {
        scanf("%d %d",&t,&r);
        sum = nCr(n,r);
        while(--t)
        {
            n = n - r;
            scanf("%d",&r);
            sum = sum * nCr(n,r);
        }
        printf("%llu\n",sum);
    }
    return 0;
}


unsigned long long nCr(int n , int r)
{
    unsigned long long ans = 1;
    r = r > (n - r) ? r : (n - r);
    for(int i = 1 ; i <= r ; i++)
    {
        ans = ans * (n - r + i);
        ans = ans / i;
    }
    return ans;
}

