#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

struct node {
    int l , r , id;
    node(){}
    node(int a , int b , int c) { l = a ; r = b ; id = c; }
};

int s ;
node Q[200010];
int ar[30010];
int ans[200010];
int cnt[1000010];

bool cmp(node a , node b)
{
    if(a.l / s == b.l / s) return a.r < b.r;
    return a.l  < b.l ;
}

int main()
{
   // freopen("input.txt" , "r" , stdin);
    int n , m , a , b ;
    int total;
    sf("%d" , &n);
    s = ceil(sqrt(n));
    for(int i = 0 ; i < n ; ++i) sf("%d" , &ar[i]);
    sf("%d" , &m);
    for(int i = 0 ; i < m ; ++i)
    {
        sf("%d %d" , &a , &b);
        Q[i] = node(a - 1 , b - 1 , i);
    }
    sort(Q , Q + m , cmp);
    cnt[ar[0]]++;
    total = 1;
    int l = 0 , r = 0;
    for(int i = 0 ; i < m ; ++i)
    {
        while(r < Q[i].r)
        {
            r++;
            if(!cnt[ar[r]]) total++;
            cnt[ar[r]]++;
        }
        while(r > Q[i].r)
        {
            if(cnt[ar[r]] >= 1)
            {
                cnt[ar[r]]--;
                if(!cnt[ar[r]]) total--;
            }
            r--;
        }
        while(l < Q[i].l)
        {
            if(cnt[ar[l]] >= 1)
            {
                cnt[ar[l]]--;
                if(!cnt[ar[l]]) total--;
            }
            l++;
        }
        while(l > Q[i].l)
        {
            l--;
            if(!cnt[ar[l]]) total++;
            cnt[ar[l]]++;
        }
        ans[Q[i].id] = total;
    }
    for(int i = 0 ; i < m ; ++i) pf("%d\n" , ans[i]);
    return 0;
}
