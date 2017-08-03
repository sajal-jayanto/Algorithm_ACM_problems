#include <bits/stdc++.h>

#define sf scanf
#define pf printf


using namespace std;


struct tree {
    int l , r , p , f ;
    tree(){}
    tree(int a , int b , int c , int d) {l = a ; r = b ; p = c ; f = d; }
};

char str[31000];
tree seg[(4 * 31000)];

void marge(tree &a , tree b , tree c)
{
    int temp = min(b.l , c.r);
    a.p = b.p + c.p + temp;
    a.l = b.l + c.l - temp;
    a.r = b.r + c.r - temp;
    if(a.l > 0 || a.r > 0) a.f = 1;
    else a.f = 0;
}

void insert(int node , int beg , int end)
{
    if(beg == end)
    {
        seg[node] = tree(str[beg] == '(' , str[beg] == ')' , 0 , 0);
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

void update(int node , int beg , int end , int indx)
{
    if(beg == indx && end == indx)
    {
        swap(seg[node].l , seg[node].r);
        return ;
    }
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    if(indx <= mid) update(left , beg , mid , indx);
    else update(right , mid + 1 , end , indx);
    marge(seg[node] , seg[left] , seg[right]);
}


int main()
{
    //freopen("input.txt" , "r" , stdin);
    int n , m , indx , cc = 0;
    while(sf("%d" , &n) == 1)
    {
        pf("Test %d:\n" , ++cc);
        sf("%s" , str + 1);
        insert(1 , 1 , n);
        sf("%d" , &m);
        while(m--)
        {
            sf("%d" , &indx);
            if(indx) update(1 , 1 , n , indx);
            else
            {
                if(n & 1) pf("NO\n");
                else if(seg[1].f) pf("NO\n");
                else pf("YES\n");
            }
        }
    }
    return 0;
}
