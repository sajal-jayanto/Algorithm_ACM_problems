#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define MAX 500010
#define MAXP 41539
void is_prime();
int count_sum(int);
void do_it();
bool seev[MAX];
int prime[MAXP];
int count_[MAX];


int main()
{
    is_prime();
    do_it();
    int t,a,b,max,x,y,count = 0;
    scanf("%d",&t);
    while(t--)
    {
        max = 0;
        scanf("%d %d",&a,&b);
        x = a < b ? a : b;
        y = a > b ? a : b;
        for(int i = x ; i <= y ; i++)
        {
            if(max < count_[i]) max = count_[i];
        }
        printf("Case #%d:\n%d\n",++count,max);
    }
    return 0;
}

void do_it()
{
    int frist,count,n;
    for(int i = 2 ; i < MAX ; i++)
    {
        if(i == 2 || (i % 2 != 0 && seev[i] == false)) count_[i] = 1;
        else
        {
            n = i;
            count = 0;
            while(1)
            {
                frist = count_sum(n);
                if(frist ==  n) break;
                else
                {
                    count++;
                    n = frist;
                }
            }
            count_[i] = count + 1;
        }
    }
}

int count_sum(int num)
{
    int n = sqrt(num);
    int sum = 0;
    for(int i = 0 ; prime[i] <= n ; i++)
    {
        if(num % prime[i] == 0)
        {
            while(num % prime[i] == 0)
            {
                sum = sum + prime[i];
                num = num / prime[i];
            }
        }
    }
    if(num != 1) sum = sum + num;

    return sum;
}

void is_prime()
{
    int k = 0;
    prime[k++] = 2;
    int n = sqrt(MAX);
    for(int i = 3 ; i < n ; i = i + 2)
    {
        if(seev[i] == false)
        {
            for(int j = i * i ; j < MAX ; j = j + (2 * i))
            {
                seev[j] = true;
            }
        }
    }
    for(int i = 3 ; i < MAX ; i = i + 2)
    {
        if(seev[i] == false) prime[k++] = i;
    }
}
