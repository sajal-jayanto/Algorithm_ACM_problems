#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#define MAX 1005
#define MAXP 168
#define MAXC 1000000000000000000
void countn(int);
void is_prime();
void factor_count(int);
bool sive[MAX];
int prime[MAXP];
int cprime[MAXP];

using namespace std;

int main()
{
    is_prime();
    int t,num,n,c = 0;
    char f[50];
    bool flage;
    unsigned long long sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&num,f);
        n = strlen(f);
        memset(cprime,0,sizeof(cprime));
        for(int i = num ; i > 1 ; i = i - n)
        {
            factor_count(i);
        }
        sum = 1;
        flage = true;
        for(int i = 0 ; i < MAXP ; i++)
        {
           if(cprime[i] != 0)
           {
               sum = sum * (cprime[i] + 1);
               if(sum > MAXC)
               {
                   flage = false;
                   break;
               }
           }
        }
        if(flage == true) printf("Case %d: %llu\n",++c,sum);
        else printf("Case %d: Infinity\n",++c);
    }
    return 0;
}

void factor_count(int num)
{
    if(sive[num] == false)
    {
        countn(num);
        return;
    }
    int n = sqrt(num);
    for(int i = 0 ; prime[i] <= n ; i++)
    {
        if(num % prime[i] == 0)
        {
            while(num % prime[i] == 0)
            {
                num = num / prime[i];
                cprime[i]++;
            }
        }
    }
    if(num != 1) countn(num);
}
void is_prime()
{
    int k = 0;
    int n = sqrt(MAX);
    for(int i = 2 ; i <= n ; i++)
    {
        if(sive[i] == false)
        {
            for(int j = i + i ; j < MAX ; j = j + i)
            {
                sive[j] = true;
            }
        }
    }
    for(int i = 2 ; i < MAX ; i++)
    {
        if(sive[i] == false)
        {
            prime[k++] = i;
        }
    }
    sive[0] = sive[1] = true;
}
void countn(int num)
{

     for(int i = 0 ; i < MAXP ; i++)
     {
         if(prime[i] == num)
         {
             cprime[i]++;
             return;
         }
     }
}
