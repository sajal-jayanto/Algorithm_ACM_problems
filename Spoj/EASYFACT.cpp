#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define MAX 100000100
#define MAXR 5761460

bool sieve[MAX];
int mobius[MAX];
int prime[MAXR + 2];

void is_prime()
{
    int n = 0 , k = sqrt(MAX);
    for(int i = 3 ; i <= k ; i = i + 2)
    {
        if(!sieve[i]) for(int j = i * i ; j < MAX ; j = j + (2 * i)) sieve[j] = true;
    }
    for(int i = 3 ; i < MAX ; i = i + 2) if(!sieve[i]) prime[n++] = i;
}


long long big_mod(long long num , int p , long long mod)
{
    long long sum = 1 , temp = num;
    while(p)
    {
        if(p & 1) sum = (sum * temp) % mod;
        temp = (temp * temp) % mod;
        p = p >> 1;
    }
    return sum;
}

int times(int n , int p)
{
    long long cnt = 0;
    while(n >= p)
    {
        n = (n / p);
        cnt = cnt + n;
    }
    return cnt;
}

int ar[100010];

int main()
{
    is_prime();
    int t , n , pos , low , high , mid , temp ;
    long long m , x , y , ans;
    sf("%d" , &t);
    while(t--)
    {
        ans = 1;
        sf("%d %lld" , &n , &m);
        pos = upper_bound(prime , prime + MAXR , n) - prime;
        for(int i = 0 ; prime[i] <= n ; ++i)
        {
            x = times(n , prime[i]);
            y = times(n , prime[i + 1]);
            if(x == y)
            {
                low = i , high = pos + 2;
                while(low <= high)
                {
                    mid = (low + high) >> 1;
                    if(times(n , prime[mid]) == x)
                    {
                        temp = mid;
                        low = mid + 1;
                    }
                    else high = mid - 1;
                }
                ans = ans * big_mod(x + 1 , (temp - i) + 1 , m);
                if(ans >= m) ans = ans % m;
                i = temp ;
            }
            else
            {
                ans = ans * (x + 1);
                if(ans >= m) ans = ans % m;
            }
        }
        ans--;
        if(ans < 0) ans = ans + m;
        pf("%lld\n" , ans);
    }
    return 0;
}
