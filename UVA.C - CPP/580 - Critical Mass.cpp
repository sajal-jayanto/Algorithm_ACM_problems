#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#define MAX 31
void do_it();
long long fib1[MAX];
long long fib2[MAX];
int main()
{
    //freopen("output.txt","w",stdout);
    do_it();
    int num;
    while(scanf("%d",&num) && num)
    {
        printf("%lld\n",fib2[num - 1]);
    }
    return 0;
}

void do_it()
{
    fib1[3] = 1;
    fib1[4] = 2;
    fib1[5] = 4;
    for(int i = 6 ; i < MAX ; i++)
    {
        fib1[i] = fib1[i - 1] + fib1[i - 2] + fib1[i - 3];
    }
    fib2[0] = 0;
    fib2[1] = 0;
    fib2[2] = 1;
    for(int i = 3 ; i < MAX ; i++)
    {
        fib2[i] = (fib2[i - 1] * 2) + fib1[i];
    }
}
