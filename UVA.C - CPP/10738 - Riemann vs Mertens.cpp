#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 1000005
#define MAX 1010
#define MAXP 170

using namespace std;

void is_prime();
int factor(int);
void do_it();
bool sive[MAX];
int prime[MAXP];
int ans[MAXN];
int sum[MAXN];

int main()
{
    freopen("output.txt","w",stdout);
    do_it();
    int n;
    while(scanf("%d",&n) && n)
    {
        printf("%8d%8d%8d\n",n,ans[n],sum[n]);
    }
    return 0;
}
void do_it()
{
    is_prime();
    ans[1] = 1;
    for(int i = 2 ; i < MAXN ; i++)
    {
        sum[i] = ans[i] = factor(i);
    }
    sum[1] = 1;
    for(int i = 2 ; i < MAXN ; i++)
    {
        sum[i] = sum[i] + sum[i - 1];
    }

}
int factor(int num)
{
    int count, p = 0;
    int n = sqrt(num);
    for(int i = 0 ; prime[i] <= n ; i++)
    {
        if(num % prime[i] == 0)
        {
            count = 0;
            while(num % prime[i] == 0)
            {
                num = num / prime[i];
                count++;p++;
                if(count > 1) return 0;
            }
        }
    }
    if(num != 1) p++;
    if(p % 2 == 0) return  1;
    else return -1;
}
void is_prime()
{

    int k = 0;
    int n = sqrt(MAX);
    prime[k++] = 2;
    for(int i = 3 ; i <= n ; i++)
    {
        if(sive[i] == false)
        {
            for(int j = i * i ; j < MAX ; j = j + (2 * i))
            {
                sive[j] = true;
            }
        }
    }
    for(int i = 3 ; i < MAX ; i = i + 2)
    {
        if(sive[i] == false) prime[k++] = i;
    }
}
