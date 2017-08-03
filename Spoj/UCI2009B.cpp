#include <bits/stdc++.h>

#define pf printf
#define sf scanf
#define MAX 1005

using namespace std;

bool sive[MAX];
int mp[MAX][170] , cnt ;
int prime[200];

void is_prime()
{
    int k = sqrt(MAX);
    cnt = 0;
    prime[cnt++] = 2;
    for(int i = 3 ; i <= k  ; i = i + 2)
    {
        if(!sive[i]) for(int j = i * i ; j < MAX ; j = j + (i * 2) ) sive[j] = true;
    }
    for(int i = 3 ; i < MAX ; i = i + 2) if(!sive[i]) prime[cnt++] = i;
}


void factor(int num)
{
    int te = num;
    for(int i = 0 ; prime[i] * prime[i] <= num ; ++i)
    {
        if(num % prime[i] == 0)
        {
            int cnt = 0;
            while(num % prime[i] == 0) { num = num / prime[i]; ++cnt; }
            mp[te][i] += cnt;
        }
    }
    if(num != 1)
    {
        int pos = upper_bound(prime , prime + cnt , num) - prime;
        mp[te][pos - 1] += 1;
    }
}

void print(int n , int r)
{
    int temp;
    for(int i = 0 ; i < 170 ; ++i)
    {
       temp = mp[n][i] - mp[r][i] - mp[n - r][i];
       if(temp == 1) pf("%dx" , prime[i]);
       else if(temp >= 2) pf("%d^%dx" , prime[i] , temp);
    }
}

int main()
{
 //   freopen("input.txt" , "r" , stdin);
//    freopen("outut.txt" , "w" , stdout);
    is_prime();
    for(int i = 2 ; i < MAX ; ++i) factor(i);
    for(int i = 0 ; i < 170 ; ++i)
    {
        for(int j = 1 ; j < MAX ; ++j) mp[j][i] += mp[j - 1][i];
    }
    int t , n , s , e ;
    long long temp ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &n);
        if(n == 0)
        {
            pf("1\n");
            continue;
        }
        s = n , e = 0;
        for(int i = 0 ; i <= n ; ++i)
        {
            if(i) pf("+");
            print(n , e);
            if(s) pf("A");
            if(s > 1) pf("^%d" , s);
            if(e) pf("B");
            if(e > 1) pf("^%d" , e);
            s--; e++;
        }
        pf("\n");
    }
    return 0;
}
