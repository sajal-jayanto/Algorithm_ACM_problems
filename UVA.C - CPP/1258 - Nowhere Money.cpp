#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
#define MAX 91
void do_it();
unsigned long long fib[MAX];
short int count[MAX];
int main()
{
    //freopen("output.txt","w",stdout);
    do_it();
    unsigned long long num;
    int k;
    while(scanf("%llu",&num) != EOF)
    {
        k = 0;
        printf("%llu\n",num);
        for(int i = MAX - 1 ; i > 0 ; i--)
        {
            if(num >= fib[i])
            {
                count[k++] = i;
                num = num - fib[i];
            }
        }
        for(int i = 0 ; i < k ; i++)
        {
            printf("%d ",count[i]);
        }
        printf("\n");
        for(int i = 0; i < k ; i++)
        {
            printf("%llu ",fib[count[i]]);
        }
        printf("\n\n");
    }
    return 0;
}
void do_it()
{
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2 ; i < MAX ; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}


