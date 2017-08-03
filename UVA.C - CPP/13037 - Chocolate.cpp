#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

set < int > x;
set < int > y;
set < int > z;
set < int > ::iterator it , one , two ;

int main()
{
   // freopen("input.txt" , "r" , stdin);
    int t , a , b , c , temp , cc = 0;
    int ans[8];
    sf("%d" , &t);
    while(t--)
    {
        x.clear(); y.clear(); z.clear();
        memset(ans , 0 , sizeof(ans));
        sf("%d %d %d" , &a , &b , &c);
        for(int i = 0 ; i < a ; ++i)
        {
            sf("%d" , &temp);
            x.insert(temp);
        }
        for(int i = 0 ; i < b ; ++i)
        {
            sf("%d" , &temp);
            y.insert(temp);
        }
        for(int i = 0 ; i < c ; ++i)
        {
            sf("%d" , &temp);
            z.insert(temp);
        }
        for(it = x.begin() ; it != x.end() ; ++it)
        {
            one = y.find((*it));
            two = z.find((*it));
            if(one == y.end() && two == z.end()) ans[0]++;
            if(one == y.end() && two != z.end()) ans[4]++;
            if(one != y.end() && two == z.end()) ans[5]++;
        }
        for(it = y.begin() ; it != y.end() ; ++it)
        {
            one = x.find((*it));
            two = z.find((*it));
            if(one == x.end() && two == z.end()) ans[1]++;
            if(one == x.end() && two != z.end()) ans[3]++;
            if(one != x.end() && two == z.end()) ans[5]++;
        }
        for(it = z.begin() ; it != z.end() ; ++it)
        {
            one = x.find((*it));
            two = y.find((*it));
            if(one == x.end() && two == y.end()) ans[2]++;
            if(one == x.end() && two != y.end()) ans[3]++;
            if(one != x.end() && two == y.end()) ans[4]++;

        }
        pf("Case #%d:\n" , ++cc);
        pf("%d %d\n" , ans[0] , ans[3] >> 1);
        pf("%d %d\n" , ans[1] , ans[4] >> 1);
        pf("%d %d\n" , ans[2] , ans[5] >> 1);
    }
    return 0;
}
