#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

vector < int > ve;

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t , n , d , temp , mx , cc = 0;
    char ch ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d" , &n , &d);
        ve.push_back(0);
        ve.push_back(0);
        ve.push_back(d);
        ve.push_back(d);
        mx = 0;
        while(n--)
        {
            sf(" %c-%d" , &ch , &temp);
            ve.push_back(temp);
            if(ch == 'B') ve.push_back(temp);
        }
        sort(ve.begin() , ve.end());
        for(int i = 2 ; i < ve.size() ; ++i) mx = max(mx , ve[i] - ve[i - 2]);
        pf("Case %d: %d\n" , ++cc , mx);
        ve.clear();
    }
    return 0;
}
