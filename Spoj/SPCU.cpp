#include <bits/stdc++.h>


#define sf scanf
#define pf printf
#define MAX 10010

using namespace std;



int main()
{
    int t , n , temp ;
    bool flag ;
    sf("%d" , &t);
    while(t--)
    {
        flag = true;
        sf("%d" , &n);
        for(int i = 0 ; i < n ; ++i)
        {
            sf("%d" , &temp);
            if(temp > i) flag = false;
        }
        if(flag) pf("YES\n");
        else pf("NO\n");
    }
    return 0;
}
