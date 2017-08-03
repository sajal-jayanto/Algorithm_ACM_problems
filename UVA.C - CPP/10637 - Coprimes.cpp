#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define MAX 10000

using namespace std;

template < class T > inline T gcd(T a,T b) { if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b); }

int s , n  , temp ;
int num[50];
int ve[105][105];

void call(int take , int sum)
{
    if(take > n || sum > s) return ;
    int k = num[take - 1];
    for(int i = take - 2 ; i >= 0  ; --i) if(ve[ num[i] ][k] != 1) return ;
    if(take == n && sum == s)
    {
        pf("%d", num[0]);
        for(int i = 1 ; i < n ; ++i) pf(" %d" , num[i]);
        pf("\n");
        return ;
    }
    for(int i = k ; i <= s - (n - 2); ++i)
    {
       num[take] = i;
       call(take + 1 , sum + i);
    }
}

int main()
{
   // freopen("input.txt" , "r" , stdin);
    for(int i = 1 ; i < 101 ; ++i) for(int j = 1 ; j < 101 ; ++j) ve[i][j] = gcd(i , j);
    int t , cc = 0;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d" , &s , &n);
        pf("Case %d:\n" , ++cc);
        call(0 , 0 );
    }
    return 0;
}
