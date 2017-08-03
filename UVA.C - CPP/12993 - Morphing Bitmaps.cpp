#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

struct node {
    int x , y ;
    node(){}
    node(int a , int b) { x = a ; y = b; }
};

vector < node > one;

int dis(node a , node b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main()
{
   // freopen("input.txt" , "r" , stdin);
    int r , c , len , mn , ans , cc = 0  , cnt ;
    node temp;
    char ch ;
    while(sf("%d %d" , &r , &c) && (r || c))
    {
        for(int i = 1 ; i <= r ; ++i)
        {
            for(int j = 1 ; j <= c ; ++j)
            {
                sf(" %c" , &ch);
                if(ch == '#') one.push_back(node(i , j));
            }
        }
        ans = 0;
        cnt = 0;
        len = one.size();
        for(int i = 1 ; i <= r ; ++i)
        {
            for(int j = 1 ; j <= c ; ++j)
            {
                sf(" %c" , &ch);
                if(ch == '#')
                {
                    ++cnt;
                    mn = (1 << 30);
                    temp = node(i , j);
                    for(int k = 0 ; k < len ; ++k) mn = min(mn , dis(temp , one[k])) ;
                    ans = max(ans , mn);
                }
            }
        }
        if(ans == 0 && len != cnt) ans = 1;
        pf("Case %d: %d\n" , ++cc , ans);
        one.clear();
    }
    return 0;
}
