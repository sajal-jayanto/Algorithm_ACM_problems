#include <bits/stdc++.h>

using namespace std;

#define pf printf
#define sf scanf

char str[75][75];
int sz[75];

int call(int x , int y)
{
    int cnt = 0;
    int cn , k;
    for(int i = 0 ; i < sz[y] ; ++i)
    {
        cn = 0 ; k = i;
        for(int j = 0 ; j < sz[x] ; ++j)
        {
            if(k >= sz[y]) k = 0 , cn = 0;
            if(str[x][j] == str[y][k]) cn++;
            cnt = max(cnt , cn);
            ++k;
        }
    }
    return cnt;
}


int main()
{
  //  freopen("input.txt" , "r" , stdin);
    int t , n , k , len , mx ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &n);
        mx = 0;
        for(int i = 0 ; i < n ; ++i)
        {
            sf("%s" , str[i]);
            sz[i] = strlen(str[i]);
        }
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = i + 1 ; j < n ; ++j)
            {
                mx = max(mx , call(i , j));
            }
        }
        pf("%d\n", mx);
    }
    return 0;
}
