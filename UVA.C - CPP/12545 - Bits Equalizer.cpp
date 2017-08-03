#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

int t , cc = 0;
char one[105];
char two[105];
vector < int > ve;

int main()
{
  //  freopen("input.txt" , "r" , stdin);
    int t , len , x , y , cn ;
    sf("%d" , &t);
    while(t--)
    {
        x = y = cn = 0;
        sf("%s %s" , one , two);
        len = strlen(one);
        for(int i = 0 ; i < len ; ++i)
        {
            if(two[i] == '1') ++x;
            if(one[i] == '1') ++y;
            if(one[i] == '?') ++cn;
        }
        if(y > x) pf("Case %d: -1\n" , ++cc);
        else
        {
            x = abs(x - y);
            for(int i = 0 ; i < len ; ++i)
            {
                if(two[i] == '1' && one[i] == '?' && x) { one[i] = '1'; --x; }
            }
            for(int i = 0 ; i < len ; ++i)
            {
                if(one[i] == '?')
                {
                    if(x) { one[i] = '1'; --x; }
                    else one[i] = '0';
                }
            }
            ve.clear();
            for(int i = 0 ; i < len ; ++i)
            {
                if(one[i] == '1' && two[i] == '0') ve.push_back(i);
            }
            for(int i = 0 ; i < len ; ++i)
            {
                if(one[i] == '0' && two[i] == '1')
                {
                    if(!ve.empty()) { swap(one[i] , one[ve.back()]); ve.pop_back(); ++cn; }
                }
            }
            for(int i = 0 ; i < len ; ++i)
            {
                if(one[i] == '0' && two[i] == '1') { one[i] = '1' ; ++cn; }
            }
            pf("Case %d: %d\n" , ++cc , cn);
        }
    }
    return 0;
}
