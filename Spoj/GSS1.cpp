#include <bits/stdc++.h>

#define sf scanf
#define pf printf


using namespace std;

struct tree {
    int prefix , suffix , subarr , sum ;
    tree(){}
    tree(int a) { prefix = a ; suffix = a ; subarr = a ; sum = a; }
};

int ar[50010];
tree seg[(4 * 50010)];

void marge(tree &a , tree &b , tree &c)
{
    a.prefix = max(b.prefix , b.sum + c.prefix);
    a.suffix = max(c.suffix , c.sum + b.suffix);
    a.subarr = max(b.suffix + c.prefix , max(b.subarr , c.subarr));
    a.sum = b.sum + c.sum;
}

void insert(int node , int beg , int end)
{
    if(beg == end)
    {
        seg[node] = tree(ar[beg]);
        return ;
    }
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    insert(left , beg , mid);
    insert(right , mid + 1 , end);
    marge(seg[node] , seg[left] , seg[right]);
}

tree query(int node , int beg , int end , int s , int e)
{
    if(beg == s && end == e) return seg[node];
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    if(e <= mid) return query(left , beg , mid , s , e);
    else if(s > mid) return query(right , mid + 1 , end , s , e);
    else
    {
        tree ans , x , y;
        x = query(left , beg , mid , s , mid);
        y = query(right , mid + 1 , end , mid + 1 , e);
        marge(ans , x , y);
        return ans;
    }
}

int main()
{

    int n , m , x , y;
    tree ans;
    sf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i) sf("%d" , &ar[i]);
    insert(1 , 1 , n);
    sf("%d" , &m);
    while(m--)
    {
        sf("%d %d" , &x , &y);
        ans = query(1 , 1 , n , x , y);
        pf("%d\n" , ans.subarr);
    }
    return 0;
}
