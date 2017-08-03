#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define MAX 1000000007

typedef unsigned long long ull;

ull H[200010];
int ar[200010];
vector < int > ve;

bool cmp(int idx , int m )
{
    int cnt = 0;
    for(int i = idx ; i < idx + m ; ++i)
    {
        if(ar[i] == ve[cnt]) { ++cnt ; continue; }
        if(ar[i] > ve[cnt]) return false;
        if(ar[i] < ve[cnt]) break ;
        ++cnt;
    }
    if(cnt == m) return false;
    cnt = 0;
    for(int i = idx ; i < idx + m ; ++i)
    {
        ve[cnt++] = ar[i];
    }
    return true;
}


int main()
{
   // freopen("input.txt" , "r" , stdin);
    H[0] = 1;
    for(int i = 1 ; i < 200002 ; ++i) H[i] = (H[i - 1] * MAX);
    int t , n , m , temp , ans , cc = 0;
    bool flag ;
    ull pat , mach ;
    sf("%d" , &t);
    while(t--)
    {
        pat = mach = 0;
        sf("%d %d", &n , &m);
        for(int i = 0 ; i < n ; ++i) sf("%d" , &ar[i]);
        for(int i = 0 ; i < m ; ++i)
        {
            sf("%d" , &temp);
            mach = mach + H[ar[i]];
            pat = pat + H[temp];
        }
        ans = 0;
        temp = (n - m);
        for(int i = 0 ; i <= temp ; ++i)
        {
            if(pat == mach)
            {
                if(!ans)
                {
                    for(int j = i ; j < i + m ; ++j) ve.push_back(ar[j]);
                    ans = i + 1;
                }
                else if(cmp(i , m)) ans = i + 1;
            }
            mach = mach - H[ar[i]] + H[ar[i + m]];
        }
        ve.clear();
        pf("Case %d: %d\n" , ++cc , ans);
    }
    return 0;
}
