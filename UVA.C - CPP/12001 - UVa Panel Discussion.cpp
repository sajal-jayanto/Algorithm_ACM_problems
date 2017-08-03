#include <bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

long long ncr(int n , int r)
{
    if(n < r) return 0ll;
    if(r > n - r) r = n - r;
	long long ans = 1;
	for(long long i = 1 ; i <= r ; i++)
	{
		ans = ans * 1ll *(n - i + 1);
		ans = ans / i;
	}
	return ans;
}

int n , m ;
int ar[100];

int main()
{
   // freopen("input.txt" , "r" , stdin);
    int temp;
    long long one , two ;
    while(sf("%d %d" , &n , &m) && (n || m))
    {
        memset(ar , 0 , sizeof(ar));
        for(int i = 0 ; i < n ; ++i)
        {
            sf("%d" , &temp);
            ar[temp]++;
        }
        one = 0 , two = ncr(n , 4);
        for(int i = 1 ; i <= m ; ++i)
        {
            if(ar[i] >= 3) one = one + ncr(ar[i] , 3);
        }
        for(int i = 1 ; i <= m ; ++i)
        {
            for(int j = i + 1 ; j <= m ; ++j)
            {
                if(ar[i] >= 2 && ar[j] >= 2) two = two - (ncr(ar[i] , 2) * ncr(ar[j] , 2));
                for(int k = j + 1 ; k <= m ; ++k)
                {
                    one = one + (ar[i] * ar[j] * ar[k]);
                }
            }
        }
        pf("%lld %lld\n" , one , two);
    }
    return 0;
}
