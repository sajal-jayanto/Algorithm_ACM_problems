#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

char str[100010];
int ar[100010];
vector < char > ch[100010];
vector < int > id[100010];
map < int , int > mp;

int find_set(int x)
{
    if(ar[x] == x) return x;
    return ar[x] = find_set(ar[x]);
}

int main()
{
   // freopen("input.txt" , "r" , stdin);
    int t , n , len, x , y , a , b;
    sf("%d" , &t);
    while(t--)
    {
        sf("%s" , str);
        len = strlen(str);
        for(int i = 0 ; i <= len ; ++i) ar[i] = i;
        sf("%d" , &n);
        while(n--)
        {
            sf("%d %d" , &x , &y);
            a = find_set(x); b = find_set(y);
            if(a != b) ar[a] = b;
        }
        x = 0;
        for(int i = 0 ; i < len ; ++i)
        {
            ar[i] = find_set(ar[i]);
            if(mp.find(ar[i]) != mp.end())
            {
                y = mp[ar[i]];
                ch[y].push_back(str[i]);
                id[y].push_back(i);
            }
            else
            {
                ch[x].push_back(str[i]);
                id[x].push_back(i);
                mp[ar[i]] = x;
                x++;
            }
        }
        for(int i = 0 ; i < x ; ++i)
        {
            len = ch[i].size();
            sort(ch[i].begin() , ch[i].end());
            sort(id[i].begin() , id[i].end());
            for(int j = 0 ; j < len ; ++j) str[id[i][j]] = ch[i][j];
            ch[i].clear(); id[i].clear();
        }
        mp.clear();
        pf("%s\n" , str);
    }
    return 0;
}
