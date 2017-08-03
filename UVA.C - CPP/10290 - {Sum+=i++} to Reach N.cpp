#include <bits/stdc++.h>

using namespace std ;

#define sf scanf
#define pf printf

#define MAX 40000000
#define MAXR 2433653

bool sive[MAX];
long long prime[MAXR];

void is_prime()
{
    int k = sqrt(MAX) , cnt = 0;
    for(int i = 3 ; i <= k ; i = i + 2)
    {
        if(!sive[i]) for(int j = i * i ; j < MAX ; j = j + (2 * i)) sive[j] = true;
    }
    for(int i = 3 ; i < MAX ; i = i + 2) if(!sive[i]) prime[cnt++] = (long long) i;
}


long long div(long long n)
{
    while(n % 2 == 0) n = n / 2;
    long long ret = 1 ;
    int k = sqrt(n);
    for(int i = 0 ; prime[i] <= k ; ++i)
    {
        if(n % prime[i] == 0)
        {
            long long cnt = 0;
            while(n % prime[i] == 0)
            {
                ++cnt;
                n = n / prime[i];
            }
            k = sqrt(n);
            ret = ret * (cnt + 1);
        }
    }
    if(n > 1) ret = ret * 2;
    return ret;
}

int main()
{
    is_prime() ;
    long long num ;
    while(sf("%lld" , &num) != EOF)
    {
        if(!num) pf("0\n");
        else pf("%lld\n" , div(num));
    }
    return 0;
}
