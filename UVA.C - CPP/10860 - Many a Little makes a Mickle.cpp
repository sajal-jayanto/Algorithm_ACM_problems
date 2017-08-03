#include<bits/stdc++.h>
#define sf scanf
#define pf printf
#define base 1000000007

using namespace std;

typedef long long ull;

struct node {

    ull h , rh ;
    int len;
    node(){}
    node(ull a , ull b , int l) { h = a ; rh = b , len = l; }

};

vector < node > ve;
ull H[10010] , one[10010];
int dp[10010] , vis[10010];
char str[10010];
int lim , te , cc = 0;


bool is_ok(int a , int b)
{
    ull hs = one[a] - (one[a + ve[b].len] * H[ve[b].len]);
    if(hs == ve[b].h || hs == ve[b].rh) return true;
    return false;
}

int call(int pos)
{
    if(pos >= lim) return 0;
    int &ret = dp[pos];
    if(vis[pos] == cc) return ret;
    ret = 50000;
    for(int i = 0 ; i < te ; ++i)
    {
        if(pos + ve[i].len <= lim && is_ok(pos , i))
        {
            ret = min(ret , call(pos + ve[i].len) + 1);
        }
    }
    vis[pos] = cc;
    return ret;
}

int main()
{
//    freopen("input.txt" , "r" , stdin);
    ull x , y ;
    H[0] = 1;
    for(int i = 1 ; i < 10010 ; ++i) H[i] = H[i - 1] * base;
    int t , len , ans;
    sf("%d" , &t);
    while(t--)
    {
        sf("%s" , str);
        lim = strlen(str);
        one[lim] = 0;
        for(int i = lim - 1 ; i >= 0 ; --i) one[i] = one[i + 1] * base + str[i];
        sf("%d" , &te);
        for(int k = 0 ; k < te ; ++k)
        {
            sf("%s" , str);
            len = strlen(str);
            x = 0; y = 0;
            for(int i = len - 1 , j = 0 ; i >= 0 ; j++ , --i)
            {
                x = x * base + str[i];
                y = y * base + str[j];
            }
            ve.push_back(node(x , y , len));
        }
        ++cc;
        ans = call(0) ;
        if(ans == 50000) pf("Set %d: Not possible.\n" , cc);
        else pf("Set %d: %d.\n", cc , ans);
        ve.clear();
    }
    return 0;
}
