#include <bits/stdc++.h>

#define sf scanf
#define pf printf

using namespace std;

map < int , int > mp;
map < int , int > ::iterator it;
int ar[100];
int br[100];

int main()
{
    int t , n , m , k , cnt , len , id ;
    long long ans ;
    sf("%d" , &t);
    while(t--)
    {
        ans = 1;
        len = 0;
        sf("%d %d" , &n , &m);
        if(n > m) swap(n , m);
        k = sqrt(n);
        for(int i = 2 ; i <= k ; ++i)
        {
            if(n % i == 0)
            {
                cnt = 0;
                while(n % i == 0)
                {
                    ++cnt;
                    n = n / i;
                }
                if(mp.find(i) == mp.end())
                {
                    mp[i] = len;
                    ar[len] = ar[len] + cnt;
                    ++len;
                }
                else
                {
                    id = mp[i];
                    ar[id] = ar[id] + cnt;
                }
            }
            if(m % i == 0)
            {
                cnt = 0;
                while(m % i == 0)
                {
                    ++cnt;
                    m = m / i;
                }
                if(mp.find(i) == mp.end())
                {
                    mp[i] = len;
                    br[len] = br[len] + cnt;
                    ++len;
                }
                else
                {
                    id = mp[i];
                    br[id] = br[id] + cnt;
                }
            }
        }
        if(n != 1)
        {
            if(mp.find(n) == mp.end())
            {
                mp[n] = len;
                ar[len] = ar[len] + 1;
                ++len;
            }
            else
            {
                id = mp[n];
                ar[id] = ar[id] + cnt;
            }
            cnt = 0;
            while(m >= n && m % n == 0)
            {
                ++cnt;
                m = m / n;
            }
            if(mp.find(n) == mp.end())
            {
                mp[n] = len;
                br[len] = br[len] + cnt;
                ++len;
            }
            else
            {
                id = mp[n];
                br[id] = br[id] + cnt;
            }
        }
        if(m != 1)
        {
            if(mp.find(m) == mp.end())
            {
                mp[m] = len;
                br[len] = br[len] + 1;
                ++len;
            }
            else
            {
                id = mp[m];
                br[id] = br[id] + cnt;
            }
            cnt = 0;
            while(n >= m && n % m == 0)
            {
                ++cnt;
                n = n / m;
            }
            if(mp.find(m) == mp.end())
            {
                mp[m] = len;
                ar[len] = ar[len] + cnt;
                ++len;
            }
            else
            {
                id = mp[m];
                ar[id] = ar[id] + cnt;
            }
        }
        k = 0;
        for(it = mp.begin() ; it != mp.end() ; ++it)
        {
            if(ar[k] != br[k])
            {
                cnt = max(ar[k] , br[k]);
                while(cnt--) ans = ans * (it->first) ;
            }
            k++;
        }
        pf("%lld\n" , ans);
        mp.clear();
        for(int i = 0 ; i <= len ; ++i) ar[i] = br[i] = 0;
    }
    return 0;
}
