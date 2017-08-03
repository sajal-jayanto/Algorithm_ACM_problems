
#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define MAX 10000010

bool sieve[MAX];
int mobius[MAX];
vector < int > prime;

void is_prime()
{
    int k = sqrt(MAX);
    prime.push_back(2);
    for(int i = 3 ; i <= k ; i = i + 2)
    {
        if(!sieve[i]) for(int j = i * i ; j < MAX ; j = j + (2 * i)) sieve[j] = true;
    }
    for(int i = 3 ; i < MAX ; i = i + 2) if(!sieve[i]) prime.push_back(i);
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    is_prime();
    for(int i = 1 ; i < MAX ; i++) mobius[i] = 1;
    int temp , k = sqrt(MAX);
    for(int i = 0 ; prime[i] <= k ; ++i)
    {
        temp = prime[i] * prime[i];
        for(int j = temp ; j < MAX ; j = j + temp) mobius[j] = 0;
    }
    for(int i = 0 ; i < prime.size() ; ++i)
    {
        for(int j = prime[i] ; j < MAX ; j = j + prime[i]) mobius[j] = mobius[j] * -1;
    }
    int t ;
    long long num , ans , te ;
    sf("%d" , &t);
    while(t--)
    {
        ans = 0;
        sf("%lld" , &num);
        k = sqrt(num);
        for(int i = 1 ; i <= k ; ++i)
        {
            if(!mobius[i]) continue;
            te = num / (i * 1ll *i);
            if(mobius[i] == -1) ans = ans - te;
            else ans = ans + te;
        }
        pf("%lld\n" , ans);
    }
    return 0;
}
