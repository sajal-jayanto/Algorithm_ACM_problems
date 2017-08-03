#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define MAX 100010

map < int , int > mp;

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t , n , temp , cc = 0;
    bool flag ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &n);
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                sf("%d" , &temp);
                mp[temp]++;
            }
        }
        flag = true;
        for(auto x : mp)
        {
            if(x.second > n) { flag = false; break; }
        }
        if(flag) pf("Case %d: yes\n" , ++cc);
        else pf("Case %d: no\n" , ++cc);
        mp.clear();
    }
    return 0;
}
