#include<bits/stdc++.h>
#define sf scanf
#define pf printf
using namespace std;

char str[200000];

int main()
{
   // freopen("input.txt" , "r" , stdin);
    int t , len , x , y , z , ans , cc = 0;
    sf("%d" , &t);
    while(t--)
    {
        sf("%s" , str);
        len = strlen(str);
        x = y = z = ans = 0;
        for(int i = 0 ; i < len ; ++i)
        {
            if(str[i] == '^' && y) { y--;  ans++; }
            else if(str[i] == '^')
            {
                if(z && ans) { y++; z--; }
                else x++;
            }
            else if(str[i] == '_' && x) { x--; y++; }
            else if(str[i] == '_' && ans > z) z++;
        }
        pf("Case %d: %d\n" , ++cc , ans);
    }
    return 0;
}
