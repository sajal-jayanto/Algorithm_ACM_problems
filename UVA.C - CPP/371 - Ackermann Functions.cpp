#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<time.h>

int main()
{
    long long i,sum,s,a,b,x,y,n,m;
    while(scanf("%lld %lld",&a,&b) == 2)
    {
        if(a == 0 && b == 0) break;
        x = 0;
        n = a < b ? a : b;
        m = a > b ? a : b;
        for(i = n;i <= m ; i++)
        {
            if(i == 1) sum = 3;
            else sum = 0;
            s = i;
            while(s != 1)
            {
                sum++;
                if(s % 2 == 0)s = s / 2;
                else s =(3 * s) + 1;
            }
            if(x < sum ){x = sum ; y = i;}
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",n,m,y,x);
    }

    return 0;
}
