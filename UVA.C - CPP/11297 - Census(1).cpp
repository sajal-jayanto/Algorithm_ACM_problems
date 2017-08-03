#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

struct node{
    int  x , y;
};

int bord[2000][2000];
node seg[2000][(2000 * 4) + 10];

void insert(int node , int beg , int end , int indx)
{
    if(beg == end)
    {
        seg[indx][node].x = bord[indx][beg];
        seg[indx][node].y = bord[indx][beg];
        return ;
    }
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    insert(left , beg , mid , indx);
    insert(right , mid + 1 , end , indx);
    seg[indx][node].x = max(seg[indx][left].x , seg[indx][right].x);
    seg[indx][node].y = min(seg[indx][left].y , seg[indx][right].y);
}


int queary_mx(int node , int beg , int end , int s , int e , int indx)
{
    if(s <= beg && e >= end) return seg[indx][node].x;
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    if(e <= mid) return queary_mx(left , beg , mid , s , e , indx);
    else if(s > mid) return queary_mx(right , mid + 1 , end , s , e ,indx);
    else
    {
        int one = queary_mx(left , beg , mid , s, mid , indx );
        int two = queary_mx(right , mid + 1 , end , mid + 1 , e, indx);
        return max(one , two);
    }
}

int queary_mn(int node , int beg , int end , int s , int e , int indx)
{
    if(s <= beg && e >= end) return seg[indx][node].y;
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    if(e <= mid) return queary_mn(left , beg , mid , s , e , indx);
    else if(s > mid) return queary_mn(right , mid + 1 , end , s , e ,indx);
    else
    {
        int one = queary_mn(left , beg , mid , s, mid , indx );
        int two = queary_mn(right , mid + 1 , end , mid + 1 , e, indx);
        return min(one , two);
    }
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
//    freopen("output.txt" , "w" , stdout);
    int t , t1 , n , a , b , c , d  ;
    char ch;
    sf("%d %d" , &t , &t1);
    for(int i = 1 ; i <= t ; ++i)
    {
        for(int j = 1 ; j <= t1 ; ++j) sf("%d" , &bord[i][j]);
    }
    for(int i = 1 ; i <= t ; ++i) insert(1 , 1 , t1 , i);
    sf("%d" , &n);
    while(n--)
    {
        sf(" %c" , &ch);
        if(ch == 'c')
        {
            sf("%d %d %d" , &a , &b , &c);
            bord[a][b] = c;
            insert(1 , 1 , t1 , a);
        }
        else if(ch == 'q')
        {
            sf("%d %d %d %d" , &a , &b , &c , &d) ;
            if(a > c) swap(a , c);
            if(b > d) swap(b , d);
            int mx = -(1 << 30);
            int mn =  (1 << 30);
            for(int i = a ; i <= c ; ++i)
            {
                mx = max(mx , queary_mx(1 , 1 , t1 , b ,  d , i));
                mn = min(mn , queary_mn(1 , 1 , t1 , b ,  d , i));
            }
            pf("%d %d\n" , mx , mn);
        }
    }
    return 0;
}
