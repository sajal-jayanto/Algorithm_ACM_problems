#include<bits/stdc++.h>

#define sf scanf
#define pf printf

using namespace std;

map < int , int > mp;
int num[100010];

int main()
{
    int t , n , last ;
    long long ans ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &n);
        for(int i = 1 ; i <= n ; ++i) sf("%d" , &num[i]);
        ans = 0;  last = 0;
        for(int i = 1 ; i <= n ; ++i)
        {
            if(mp[ num[i] ] > last ) last = mp[ num[i] ];
            ans = ans + (i - last);
            mp[ num[i] ] = i;
        }
        pf("%lld\n" , ans);
        mp.clear();
    }
    return 0;
}
