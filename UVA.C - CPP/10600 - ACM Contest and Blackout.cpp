#include<bits/stdc++.h>

#define sf scanf
#define pf printf

using namespace std;

struct node {

    int u , v , w;
    node(){}
    node(int x , int y , int z) { u = x ; v = y ; w = z; }
    bool operator < (const node &t) const {
        return w < t.w;
    }
};

vector < node > ve ;
vector < int > path , ans ;
int dis_set[110];

int find_set(int x)
{
    if(dis_set[x] == x) return x;
    return dis_set[x] = find_set(dis_set[x]);
}


int mst(int total , int id)
{
    for(int i = 0 ; i <= total ; ++i) dis_set[i] = i;
    int sum = 0 , cnt = 0;
    int len = ve.size() , x , y ;
    for(int i = 0 ; i < len ; ++i)
    {
        if(id == i) continue ;
        x = find_set(ve[i].u);
        y = find_set(ve[i].v);
        if(x != y)
        {
            ++cnt;
            dis_set[x] = y;
            sum = sum + ve[i].w;
            if(id == -1) path.push_back(i);
            if(cnt == total - 1) return sum;
        }
    }
    if(cnt == total - 1) return sum;
    return -1;
}


int main()
{
//    freopen("input.txt" , "r" , stdin);
    int t , a , b , x , y , w , best , sbest , cc = 0;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d" , &a , &b);
        while(b--)
        {
            sf("%d %d %d" , &x , &y , &w);
            ve.push_back(node(x , y , w));
        }
        sort(ve.begin() , ve.end());
        ans.push_back(mst(a , -1));
        for(int i = 0 ; i < path.size() ; ++i)
        {
            x = mst(a , path[i]);
            if(x != -1) ans.push_back(x);
        }
        sort(ans.begin() , ans.end());
        if(ans.size() <= 1) pf("%d %d\n", ans[0] , ans[0]);
        else pf("%d %d\n" , ans[0] , ans[1]);
        path.clear(); ve.clear(); ans.clear();
    }
    return 0;
}
