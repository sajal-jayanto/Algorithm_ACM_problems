#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>
#define MAX 110
#define MAXP 30
void is_prime();
void factor(int);
bool seev[MAX];
int prime[50];
int p;
struct bord {

    int p;
    int c;

} bord[MAXP];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    is_prime();
    int t,n,num,sum,r,count = 0;
    bool flage;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&num);
        factor(n);
        flage = true;
        for(int i = 0 ; i < p ; i++)
        {
            sum = 0;
            r = num;
            while(r >= bord[i].p)
            {
                sum = sum + r / bord[i].p;
                r = r / bord[i].p;
            }
            if(sum < bord[i].c)
            {
                printf("Case %d:\nImpossible to divide\n",++count);
                flage = false;
                break;
            }
            if(sum != 0) bord[i].c = sum / bord[i].c;
        }
        if(flage == true)
        {
            sum = bord[0].c;
            for(int i =0 ; i < p ; i++)
            {
                if(sum > bord[i].c) sum = bord[i].c;
            }
            printf("Case %d:\n%d\n",++count,sum);
        }
    }
   return 0;
}

void factor(int num)
{
    p = 0;
    int n = sqrt(num);
    int count;
    for(int i = 0 ; prime[i] <= n ; i++)
    {
        if(num % prime[i] == 0)
        {
            count = 0;
            while(num % prime[i] == 0)
            {
                count++;
                num = num / prime[i];
            }
            bord[p].p = prime[i];
            bord[p].c = count;
            p++;
        }
    }
    if(num != 1)
    {
        bord[p].p = num;
        bord[p].c = 1;
        p++;
    }
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
                seev[j] = i;
            }
        }
    }
    for(int i = 3 ; i < MAX ; i = i + 2)
    {
        if(seev[i] == false) prime[k++] = i;
    }
}
