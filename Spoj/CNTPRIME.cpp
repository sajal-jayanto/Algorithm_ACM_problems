#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define MAX 1000010

using namespace std;


struct tree {
    int cnt , lazy ;
    tree() { lazy = 0 ; cnt = 0; }
};

bool sive[MAX];
int ar[10010];
tree seg[(4 * 10010)];


void is_prime()
{
    sive[0] = sive[1] = true;
    for(int i = 4 ; i < MAX ; i = i + 2) sive[i] = true;
    int k = sqrt(MAX);
    for(int i = 3 ; i <= k ; i = i + 2)
    {
        if(!sive[i]) for(int j = i * i ; j < MAX ; j = j + (2 * i)) sive[j] = true;
    }
}

void insert(int node , int beg , int end)
{
    if(beg == end)
    {
        seg[node].cnt = !sive[ar[beg]];
        seg[node].lazy = 0;
        return ;
    }
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    insert(left , beg , mid);
    insert(right , mid + 1 , end);
    seg[node].cnt = seg[left].cnt + seg[right].cnt;
    seg[node].lazy = 0;
}

void update_lazy(int node , int beg , int end , int flag)
{
    seg[node].cnt = !sive[flag] ? (end - beg + 1) : 0;
    seg[node].lazy = flag;
}

void update(int node , int beg , int end , int s , int e , int flag)
{
    if(s == beg && e == end)
    {
        seg[node].cnt = !sive[flag] ? (end - beg + 1) : 0;
        seg[node].lazy = flag;
        return ;
    }
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    if(seg[node].lazy)
    {
        update_lazy(left , beg , mid , seg[node].lazy);
        update_lazy(right , mid + 1 , end , seg[node].lazy);
    }
    seg[node].lazy = 0;
    if(e <= mid) update(left , beg , mid , s , e , flag);
    else if(s > mid) update(right , mid + 1 , end , s , e , flag);
    else
    {
        update(left , beg , mid , s , mid , flag);
        update(right , mid + 1 , end , mid + 1 , e , flag);
    }
    seg[node].cnt = seg[left].cnt + seg[right].cnt;
}

int query(int node , int beg , int end , int s , int e)
{
    if(s == beg && e == end) return seg[node].cnt;
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    if(seg[node].lazy)
    {
        update_lazy(left , beg , mid , seg[node].lazy);
        update_lazy(right , mid + 1 , end , seg[node].lazy);
    }
    seg[node].lazy = 0;
    if(e <= mid) return query(left , beg , mid , s , e);
    else if(s > mid) return query(right , mid + 1 , end , s , e);
    return query(left , beg , mid , s , mid) + query(right , mid + 1 , end , mid + 1 , e);
}


int main()
{
 //   freopen("input.txt" , "r" , stdin);
    is_prime();
    int t , n , q , kye , x, y , temp , cc = 0;
    sf("%d" , &t);
    while(t--)
    {
        pf("Case %d:\n" , ++cc);
        sf("%d %d" , &n , &q);
        for(int i = 1 ; i <= n ; ++i) sf("%d" , &ar[i]);
        insert(1 , 1 , n);
        while(q--)
        {
            sf("%d" , &kye);
            if(kye == 1)
            {
                sf("%d %d" , &x , &y);
                pf("%d\n" , query(1 , 1 , n , x , y));
            }
            else
            {
                sf("%d %d %d" , &x , &y , &temp);
                update(1 , 1 , n , x , y , temp);
            }
        }
    }
    return 0;
}
