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
#define MAXN 50001
#define MAX 230
#define MAXP 50

using namespace std;

void is_prime();
int factor(int);
void do_it();
bool sive[MAX];
int prime[MAXP];
int ar[MAXN + 1];


int main()
{
    is_prime();
    do_it();
    int n;
    while(scanf("%d",&n) && n)
    {
        printf("%d\n",ar[n]);
    }
    return 0;
}
void do_it()
{
    for(int i = 2 ; i < MAXN ; i++)
    {
        ar[i] = factor(i);
    }
    ar[1] = 1;
    for(int i = 2 ; i < MAXN ; i++)
    {
        ar[i] = ar[i - 1] + ar[i];
    }
}
int factor(int num)
{
    int sum = num;
    int n = sqrt(num);
    for(int i = 0 ; prime[i] <= n ; i++)
    {
        if(num % prime[i] == 0)
        {
            sum = (sum * (prime[i] - 1)) / prime[i];
            while(num % prime[i] == 0) num = num / prime[i];
        }
    }
    if(num != 1 && num == sum) sum--;
    else if(num != 1) sum = (sum * (num - 1)) / num;
    sum = sum * 2;
    return sum;
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
        if(sive[i] == false)
        {
            prime[k++] = i;
        }
    }
}
