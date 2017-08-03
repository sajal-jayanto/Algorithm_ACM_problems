#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 2000001
#define MAXN 1530
#define MAXP 241
void is_prime();
int sort[MAX];
bool seev[MAX];
int prime[MAXP];
signed short int ans[MAX];

int main()
{
    is_prime();
    int num,count = 0;
    while(scanf("%d",&num) && num)
    {
        printf("Case %d: %d\n",++count,sort[num]);
    }
    return 0;
}

void is_prime()
{

    int k = 0;
    prime[k++] = 2;
    int n = sqrt(MAXN);
    for(int i = 3 ; i < n ; i = i + 2)
    {
        if(seev[i] == false)
        {
            for(int j = i * i  ; j < MAXN ; j = j + (2 * i))
            {
                seev[j] = true;
            }
        }
    }
    for(int i = 3 ; i < MAXN ; i = i + 2)
    {
        if(seev[i] == false) prime[k++] = i;
    }
    int count,num;
    for(int i = 2 ; i < MAX  ; i++)
    {
        n = sqrt(i);
        num = i;
        count = 0;
        for(int j = 0 ; prime[j] <= n ; j++)
        {
            if(num % prime[j] == 0)
            {
                while(num % prime[j] == 0)
                {
                    count++;
                    num = num / prime[j];
                }
            }
        }
        if(num != 1) count++;
        ans[i] = count;
    }
    k = 1;
    sort[k++] = 1;
    for(int i = 1 ; i <= 20  ; i++)
    {
        for(int j = 2 ; j < MAX ; j++)
        {
            if(i == ans[j])
            {
                sort[k++] = j;

            }
        }
    }
}
