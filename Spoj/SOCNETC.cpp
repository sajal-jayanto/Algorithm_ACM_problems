#include <bits/stdc++.h>


using namespace std;

#define sf scanf
#define pf printf

int dis[1000010];
int cnt[1000010];

int find(int x)
{
    if(dis[x] == x) return x;
    return dis[x] = find(dis[x]);
}

int main()
{
   // freopen("input.txt"  , "r" , stdin);
    for(int i = 0 ; i < 1000010 ; ++i) { dis[i] = i; cnt[i] = 1; }
    int t , n , m , a , b , x , y , total ;
    char ch ;
    sf("%d %d" , &n , &m);
    sf("%d" , &t);
    while(t--)
    {
        sf(" %c" , &ch);
        if(ch == 'S')
        {
            sf("%d" , &a);
            b = find(a);
            pf("%d\n" , cnt[b]);
        }
        else
        {
            sf("%d %d" , &a , &b);
            x = find(a); y = find(b);
            if(ch == 'A')
            {
                if(x == y) total = cnt[x];
                else total = cnt[x] + cnt[y];
                if(total <= m)
                {
                    dis[y] = x;
                    cnt[x] = total;
                }
            }
            else
            {
                if(x == y) pf("Yes\n");
                else pf("No\n");
            }
        }
    }
    return 0;
}
