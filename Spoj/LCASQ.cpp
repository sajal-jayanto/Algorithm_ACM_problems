#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf


vector < int > ve[10005];
int form[10005];
int level[10005];
int table[10005][15 + 1];


void dfs(int u , int v , int cnt)
{
    form[v] = u;
    level[v] = cnt;
    for(int i = 0 ; i < (int) ve[v].size() ; ++i)
    {
        int temp = ve[v][i];
        if(u == temp) continue;
        dfs(v , temp , cnt + 1);
    }
}

void bild(int n)
{
    memset(table , -1 , sizeof(table));
    for(int i = 0 ; i < n ; ++i) table[i][0] = form[i];
    for(int j = 1 ; j < 15 ; ++j)
    {
        for(int i = 0 ; i < n ; ++i)
        {
            if(table[i][j - 1] != -1) table[i][j] = table[table[i][j - 1]][j - 1];
        }
    }
}

int lca(int x , int y)
{
    if(level[x] < level[y]) swap(x , y);
    int next , cnt = 1;
    while(true)
    {
        next = cnt + 1;
        if((1 << next) > level[x]) break ;
        cnt++;
    }
    for(int i = cnt ; i >= 0 ; i--)
    {
        if(level[x] - (1 << i) >= level[y]) x = table[x][i];
    }
    if(x == y) return x;
    for(int i = cnt ; i >= 0 ; i--)
    {
        if(table[x][i] != -1 && table[x][i] != table[y][i])
        {
            x = table[x][i];
            y = table[y][i];
        }
    }
    return form[x];
}


int main()
{
   // freopen("input.txt" , "r", stdin);
    int n , m , temp , x , y;
    sf("%d" , &n);
    for(int i = 0 ; i < n ; ++i)
    {
        sf("%d" , &m);
        while(m--)
        {
            sf("%d" , &temp);
            ve[i].push_back(temp);
        }
    }
    dfs(0 , 0 , 0);
    bild(n);
    sf("%d" , &m);
    while(m--)
    {
        sf("%d %d" , &x , &y);
        temp = lca(x , y);
        pf("%d\n" , temp);
    }
    return 0;
}
