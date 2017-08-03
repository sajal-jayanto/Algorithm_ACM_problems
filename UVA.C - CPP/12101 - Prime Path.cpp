#include <bits/stdc++.h>

using namespace std;

#define sf         scanf
#define pf         printf
#define MAX 10000

bool siv[MAX];
vector < int > prime;
map < int , vector < int > > ve;
map < int , int > vis;
map < int , int > ::iterator it ;

void is_prime()
{
    int n = sqrt(MAX);
    for(int i = 3 ; i < n ; i += 2) if(!siv[i]) for(int j = i * i ; j < MAX ; j += (2 * i)) siv[j] = true;
    for(int i = 999 ; i < MAX ; i += 2) if(!siv[i])
    {
        if(i >= 1000 && i <= 9999) { prime.push_back(i); vis[i] = -1; }
    }
}

bool are_same(int a , int b)
{
    int x , y , cnt = 0;
    while(a)
    {
        x = a % 10;  y = b % 10;
        if(x != y) ++cnt;
        if(cnt > 1) return false;
        a = a / 10;  b = b / 10;
    }
    return true;
}

void bfs(int s , int e)
{
    int k , l , len ;
    vis[s] = 0;
    queue < int > Q;
    Q.push(s);
    while(!Q.empty())
    {
        k = Q.front();
        Q.pop();
        if(k == e) return ;
        len = ve[k].size();
        for(int i = 0 ; i < len ; ++i)
        {
            l = ve[k][i];
            if(vis[l] == -1)
            {
                vis[l] = vis[k] + 1;
                Q.push(l);
            }
        }
    }
}

int main()
{
    //freopen("tem.txt" , "r" , stdin);
    is_prime();
    int len = prime.size();
    for(int i = 0 ; i < len ; ++i)
    {
        for(int j = 0 ; j < len ; ++j)
        {
            if(i != j && are_same(prime[i] , prime[j]) ) ve[prime[i]].push_back(prime[j]);
        }
    }
    int t , s , e ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d" , &s , &e);
        bfs(s , e);
        if(vis[e] == -1) pf("Impossible\n");
        else pf("%d\n" , vis[e]);
        for(it = vis.begin() ; it != vis.end() ; ++it) it->second = -1;
    }
    return 0;
}

