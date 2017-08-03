#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

int num[50];
set < int > se;

int main()
{
   // freopen("input.txt" , "r" , stdin);
    int n , temp , ans ;
    while(sf("%d" , &n) == 1)
    {
        ans = 0;
        se.clear();
        for(int i = 0 ; i < n ; ++i) sf("%d" , &num[i]);
        for(int i = 0 ; i < n ; ++i)
        {
            sf("%d" , &temp);
            for(int j = 0 ; j < n ; ++j)
            {
                if(num[j] == temp) break ;
                if(se.find(num[j]) == se.end()) ++ans;
            }
            se.insert(temp);
        }
        pf("%d\n" , ans);
    }
    return 0;
}
