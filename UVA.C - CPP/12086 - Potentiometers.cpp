#include <bits/stdc++.h>

using namespace std;

#define MAX      200010
#define sf       scanf
#define pf       printf


struct tree {

    int num;
};
tree seg[(4 * MAX)];
int ar[MAX];
void insert(int node , int beg , int end);
void updet(int node , int beg , int end , int indx , int valu);
int query(int node , int beg , int end , int s , int e);

int main()
{
   // freopen("input.txt" , "r" ,stdin);
    int t , a , b , cc = 0;
    char str[10];
    while( sf("%d" , &t) && t)
    {
        if(cc) pf("\n");
        pf("Case %d:\n" , ++cc);
        for(int i = 1 ; i <= t ; ++i) sf("%d" , &ar[i]);
        insert(1 , 1 , t);
        while( sf("%s" , str) && strcmp(str ,"END"))
        {
            if(str[0] == 'M')
            {
                sf("%d %d" , &a , &b);
                pf("%d\n" , query(1 , 1 , t , a , b));
            }
            else if(str[0] == 'S')
            {
                sf("%d %d" , &a , &b);
                updet(1 , 1 , t , a , b);
            }
        }
    }
    return 0;
}


void insert(int node , int beg , int end)
{
    if(beg == end)
    {
        seg[node].num = ar[beg];
        return ;
    }
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    insert(left , beg , mid);
    insert(right , mid + 1 , end);
    seg[node].num = (seg[left].num + seg[right].num);
}

int query(int node , int beg , int end , int s , int e)
{
    if(s <= beg && e >= end) return seg[node].num;
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    if(e <= mid) return query(left , beg , mid , s , e);
    else if(s > mid) return query(right , mid + 1 , end , s , e);
    else
    {
        int one = query(left , beg , mid , s , mid);
        int two = query(right , mid + 1 , end , mid + 1 , e);
        return (one + two);
    }
}

void updet(int node , int beg , int end , int indx , int valu)
{

    if(beg == end)
    {
        seg[node].num = valu;
        return ;
    }
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    if(indx  <= mid) updet(left , beg , mid , indx , valu);
    else updet(right , mid + 1 , end , indx , valu);
    seg[node].num = (seg[left].num + seg[right].num);
}
