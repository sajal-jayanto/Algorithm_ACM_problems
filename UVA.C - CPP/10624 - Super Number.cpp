#include <bits/stdc++.h>

using namespace std;

#define pf printf
#define sf scanf


int num[105], n , m ;
bool flag ;

bool can(int pos)
{
    int sum = 0;
    for(int i = 1 ; i <= pos ; ++i)
    {
        sum = (sum * 10) + num[i];
        sum = sum % pos;
    }
    if(sum == 0) return true;
    return false;
}



void call(int pos)
{
    if(pos == m + 1)
    {
        for(int i = 1 ; i <= m ; ++i) pf("%d", num[i]);
        flag = true;
        return ;
    }
    for(int i = 0 ; i < 10 ; ++i)
    {
        if(flag) return ;
        if(pos == 1 && i == 0) continue;
        num[pos] = i;
        if(pos < n || can(pos)) call(pos + 1);
    }
}



int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t , cc = 0;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d" , &n , &m);
        flag = false;
        pf("Case %d: " , ++cc);
        call(1);
        if(!flag) pf("-1");
        pf("\n");
    }
}
