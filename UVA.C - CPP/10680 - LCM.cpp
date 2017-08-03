#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#define MAX 1000100
#define MAXP 78504
void is_prime();
bool sive[MAX];
int prime[MAXP];
int find_low_pow(int a , int b);


using namespace std;

int main()
{
    is_prime();
    int num;
    while(scanf("%d",&num) && num)
    {
        long long ans = 1;
        for(int i = 0 ;prime[i] <= num ; i++)
        {
            int n = find_low_pow(prime[i], num);
            while(n--)
            {
                ans = ans * prime[i];
                while(ans % 10 == 0) ans = ans / 10;
                ans = ans % 10000000000;
            }
        }
         printf("%lld\n", ans % 10);
    }
    return 0;
}

void is_prime()
{
    int n = sqrt(MAX);
    int k = 0;
    prime[k++] = 2;
    for(int i = 3 ; i < n ; i = i + 2) if(!sive[i]) for(int j = i * i ; j < MAX ; j = j + (2 * i)) sive[j] = true;
    for(int i = 3 ; i < MAX ; i = i + 2) if(!sive[i]) prime[k++] = i;
}

int find_low_pow(int a , int b)
{
    int cnt = 0;
    long long sum = a;
    while(b >= sum){sum = sum * a ; cnt++;}
    return cnt--;
}

