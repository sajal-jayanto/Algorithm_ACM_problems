#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

struct tree {

    int on , off , lazy;
    tree(){}
    tree(int x , int y , int a) { on = x; off = y ; lazy = a; }

};

tree seg[(4 * 100100)];

void insert(int node , int beg , int end)
{
    if(beg == end)
    {
        seg[node].on = 0;
        seg[node].off = 1;
        seg[node].lazy = 0;
        return ;
    }
    int left , right , mid ;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    insert(left , beg , mid);
    insert(right , mid + 1 , end);
    seg[node].on = seg[left].on + seg[right].on;
    seg[node].off = seg[left].off + seg[right].off;
    seg[node].lazy = seg[left].lazy + seg[right].lazy;
}


void update(int node , int beg , int end , int s , int e)
{
    if(beg == s && end == e)
    {
        seg[node].lazy++;
        swap(seg[node].on , seg[node].off);
        return ;
    }
    int left , right , mid ;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    if(e <= mid) update(left , beg , mid , s , e);
    else if(s > mid) update(right , mid + 1 , end , s , e);
    else
    {
        update(left , beg , mid , s , mid);
        update(right , mid + 1 , end , mid + 1 , e);
    }
    seg[node].on = seg[left].on + seg[right].on;
    seg[node].off = seg[left].off + seg[right].off;
    if(seg[node].lazy & 1) swap(seg[node].on , seg[node].off);
}

int query(int node , int beg , int end , int s , int e , int flip)
{
    if(beg == s && end == e)
    {
        if(flip & 1) return seg[node].off;
        return seg[node].on;
    }
    int left , right , mid ;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    flip = flip + seg[node].lazy;
    if(e <= mid) return query(left , beg , mid , s , e , flip);
    else if(s > mid) return query(right , mid + 1 , end , s , e , flip);
    else
    {
        int x = query(left , beg , mid , s , mid , flip);
        int y = query(right , mid + 1 , end , mid + 1 , e , flip);
        return x + y;
    }
}

int main()
{
   // freopen("input.txt" , "r" , stdin);
    int n , m , x , y , z;
    sf("%d %d" , &n , &m);
    insert(1 , 1 , n);
    while(m--)
    {
        sf("%d %d %d" , &x , &y , &z);
        if(!x) update(1 , 1 , n , y , z);
        else pf("%d\n" , query(1 , 1 , n , y , z , 0) );
    }
    return 0;
}
