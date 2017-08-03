#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define MAX 2147483647

struct tree {
    int mx , mn;
    tree(){}
    tree(int a , int b) { mx = a ; mn = b; }
};

int ar[505][505];
tree seg[505][(4 * 505)];

void insert(int node , int beg , int end , int r)
{
    if(beg == end)
    {
        seg[r][node].mx = ar[r][beg];
        seg[r][node].mn = ar[r][beg];
        return ;
    }
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    insert(left , beg , mid , r);
    insert(right , mid + 1 , end , r);
    seg[r][node].mx = max(seg[r][left].mx , seg[r][right].mx);
    seg[r][node].mn = min(seg[r][left].mn , seg[r][right].mn);
}

tree queary(int node , int beg , int end , int r , int s , int e)
{
    if(beg >= s && end <= e) return seg[r][node];
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    if(e <= mid) return queary(left , beg , mid , r , s , e);
    else if(s > mid) return queary(right , mid + 1  , end , r , s , e);
    else
    {
        tree one = queary(left , beg , mid , r , s , mid);
        tree two = queary(right , mid + 1  , end , r , mid + 1 , e);
        return tree(max(one.mx , two.mx) , min(one.mn , two.mn));
    }
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int n , q , x1 , y1 , x2 , y2 ;
    tree ans , temp ;
    char ch ;
    sf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = 1 ; j <= n ; ++j) sf("%d" , &ar[i][j]);
    }
    for(int i = 1 ; i <= n ; ++i) insert(1 , 1 , n , i);
    sf("%d" , &q);
    while(q--)
    {
        sf(" %c" , &ch);
        if(ch == 'c')
        {
            sf("%d %d" , &x1 , &y1);
            sf("%d" , &ar[x1][y1]);
            insert(1 , 1 , n , x1);
        }
        else
        {
            sf("%d %d %d %d" , &x1 , &y1 , &x2 , &y2);
            ans = tree(-MAX , MAX);
            for(int i = x1 ; i <= x2 ; ++i)
            {
                temp = queary(1 , 1 , n , i , y1 , y2);
                ans = tree(max(ans.mx , temp.mx) , min(ans.mn , temp.mn));
            }
            pf("%d %d\n" , ans.mx , ans.mn);
        }
    }
    return 0;
}
