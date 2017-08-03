#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

char str[1000010];

vector < int > ve[60];

int main()
{
    //freopen("input.txt" , "r" , stdin);
    //freopen("output.txt" , "w" , stdout);
    int q , len , s , e , now , pos , temp ;
    bool flag ;
    sf("%s" , str);
    len = strlen(str);
    for(int i = 0 ; i < 60 ; ++i) ve[i].push_back(-1);
    for(int i = 0 ; i < len ; ++i) ve[str[i] - 'A'].push_back(i);
    sf("%d" , &q);
    while(q--)
    {
        flag = true; now = -1;
        s = 0 ; e = 0;
        sf("%s" , str);
        len = strlen(str);
        for(int i = 0 ; i < len ; ++i)
        {
            temp = str[i] - 'A';
            pos = upper_bound(ve[temp].begin() , ve[temp].end() , now) - ve[temp].begin();
            if(pos >= ve[temp].size())
            {
                flag = false;
                break ;
            }
            else now = ve[temp][pos];
            if(i == 0) s = now;
            e = now;
        }
        !flag ? pf("Not matched\n") : pf("Matched %d %d\n" , s , e );
    }
    return 0;
}
