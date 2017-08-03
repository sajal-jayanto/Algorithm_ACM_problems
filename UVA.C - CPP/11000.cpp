#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#define MAX 55
void do_it(int);
long long fib[MAX];
int main()
{
    int n;
    while(scanf("%d",&n) && 0 <= n)
    {
        if(n == 0)
        {
            printf("0 1\n");
            continue;
        }
        if(n == 1)
        {
            printf("1 2\n");
            continue;
        }
        do_it(n);
    }
    return 0;
}

void do_it(int n)
{

    long long frist ,second ,temp;
    frist = 1;
    second = 2;
    for(int i = 0 ; i < n - 1 ; i++)
    {
        temp = frist + second;
        frist = second;
        second = temp + 1;
    }
    temp++;
    printf("%lld %lld\n",frist,temp);
}
