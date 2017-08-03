#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#define MAX 101
#define MAXP 25

using namespace std;

void is_prime();
void factor(int);
int factor2(int,int);
bool sive[MAX];
int prime[MAXP];
int nprime[MAXP];
int countf[MAXP];
int main()
{
    is_prime();
    int numf,num;
    long long sum;
    while(scanf("%d %d",&numf,&num) && (numf || num))
    {
        memset(countf,0,sizeof(countf));
        sum = 1;
        factor(numf);
        if(factor2(num,numf) == 1)
        {
            printf("0\n");
            continue;
        }
        else
        {
            for(int i = 0 ; i < MAXP ; i++)
            {
                if(countf[i] != 0) sum = sum * countf[i];
            }
        }
        printf("%lld\n",sum);
    }
}
int factor2(int num,int num1)
{

    int k = 0;
    int count;
    if(num == 1) return 0;
    if(num == 0) return 1;
    for(int i = 0 ; num1 >= prime[i] ; i++)
    {
        nprime[k++] = prime[i]; //printf("-%d ",prime[i]);
    }
    for(int i = 0 ; i < k ; i++)
    {
        if(num % nprime[i] == 0)
        {
            count = 0;
            while(num % nprime[i] == 0)
            {
                count++;
                num = num / nprime[i];
            }
            if(countf[i] != 0) countf[i] = countf[i] - count;
        }
    }
    if(num != 1) return 1;
    return 0;
}
void factor(int num)
{
    int sum;
    for(int i = 0 ; i < MAXP ;  i++)
    {
        sum = 0;
        int n = num;
        while(n >= prime[i])
        {
            sum = sum + (n / prime[i]);
            n = n / prime[i];
        }
        if(sum != 0) countf[i] = sum + 1;
    }
   // for(int i = 0 ; i < MAXP ;i++) printf("%d-->%d\n",prime[i],countf[i]);
}

void is_prime()
{
    int k = 0;
    int n = sqrt(MAX);
    prime[k++] = 2;
    for(int i = 3 ; i <= n ; i = i + 2)
    {
        if(sive[i] == false)
        {
            for(int j = i * i ; j < MAX ; j = j + (2 * i))
            {
                sive[j] = true;
            }
        }
    }
    for(int i = 3 ; i < MAX  ; i = i + 2)
    {
         if(sive[i] == false) prime[k++] = i;
    }
}
