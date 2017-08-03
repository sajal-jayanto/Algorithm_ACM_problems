#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100005
int num[MAX];
int sum[MAX];

void do_it();

int main()
{
    do_it();
    int t,a,b,k;
    long long x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&k);
        x = y = 0;
        for(int i = a ; i <= b ; i++)
        {
            if(i % k == 0)
            {
                x = x + num[i];
                y = y + sum[i];
            }
        }
        printf("%lld %lld\n",x,y);
    }
    return 0;
}

void do_it()
{
    int n;
    for(int i = 1 ; i < MAX ; i++)
    {
        n = i;
        for(int j = 1 ; j <= sqrt(n) ; j++)
        {
            if(n % j == 0)
            {
                if( n / j != j)
                {
                    num[i] =  num[i] + 2;
                    sum[i] = sum[i] + (n / j) + j;
                }
                else
                {
                    num[i] = num[i] + 1;
                    sum[i] = sum[i] + j;
                }
            }
        }
    }
}
