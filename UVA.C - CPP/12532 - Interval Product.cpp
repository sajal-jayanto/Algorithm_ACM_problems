#include <bits/stdc++.h>

using namespace std;

#define FF              freopen("input.txt" , "r" , stdin);
#define sf              scanf
#define pf              printf
#define fs              first
#define se              second
#define pb              push_back
#define ins             insert
#define Lb              lower_bound
#define Up              upper_bound
#define INF             (1<<30)
#define mem(a,b)        memset(a, b, sizeof(a))
#define MAX             18
#define MAXR            100010
#define MAXC            100010

typedef long long ll;

const double PI = 2.0 * acos(0.0);
const double eps = 1e-9;

template < class T > T Abs(T x) { return x > 0 ? x : -x; }
template < class T > string toString(T n) { ostringstream ost; ost << n; ost.flush() ; return ost.str(); }
template < class T > inline T gcd(T a,T b) { if(a < 0) return gcd(-a,b); if(b < 0)return gcd(a,-b); return (b == 0) ? a : gcd(b ,a % b); }
template < class T > inline T lcm(T a,T b) { if(a < 0) return lcm(-a,b); if(b < 0)return lcm(a,-b); return a * (b / gcd(a , b)); }
template < class T > inline T sqr(T n) { return n * n; }
template < class T > T power(T n, T p)
{
    if(!p) return 1;
    else
    {
        T sum = sqr( power( n ,  p >> 1) );
        if(p & 1) sum =  n;
        return sum;
    }
}


//ll bigmod(ll num , ll p , ll mod)
//{
//    ll sum = 1 , temp = num;
//    while(p)
//    {
//        if(p & 1) sum = (sum * temp) % mod;
//        temp = (temp * temp) % mod; p = p >> 1;
//    }
//    return sum;
//}
//

/// S , E  , N , W
//int one [] = {1 ,0,-1, 0};
//int two [] = {0 ,1, 0,-1};
///S , SE , E , NE , N , NW , W , SW
//int one [] = {1 ,1 ,0,-1,-1,-1, 0, 1};
//int two [] = {0 ,1 ,1 ,1, 0,-1,-1,-1};
///Knight Direction
//int one[]={2 ,1 ,-1,-2,-2,-1, 1, 2};
//int two[]={1 ,2 , 2, 1,-1,-2,-2,-1};


struct tree {
    int num;
};

tree seg[400100];

int ar[100100];

void insert(int node , int beg ,int end)
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
    seg[node].num = (seg[left].num * seg[right].num);
}

void updet(int node , int beg , int end , int indx ,int valu)
{
    if(beg == indx && end == indx)
    {
        seg[node].num = valu;
        return ;
    }
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    if(indx <= mid) updet(left , beg , mid , indx , valu);
    else updet(right , mid + 1 , end , indx , valu);
    seg[node].num = (seg[left].num * seg[right].num);
}

int queary(int node , int beg , int end , int s , int e)
{
    if(beg == s && end == e)
    {
        return seg[node].num;
    }
    int left , right , mid;
    left = node << 1;
    right = left + 1;
    mid = (beg + end) >> 1;
    if(e <= mid) return queary(left , beg , mid , s , e);
    else if(s > mid) return queary(right , mid + 1 , end , s , e);
    else
    {
        int one = queary(left , beg , mid , s , mid);
        int two = queary(right , mid + 1 , end , mid + 1, e);
        return (one * two);
    }
}

int main()
{
    int n , q , a , b;
    char ch;
    while(sf("%d %d" , &n , &q) == 2)
    {
        mem(seg , 0);
        for(int i = 0 ; i < n ; ++i)
        {
            sf("%d" , &ar[i]);
            if(ar[i] < 0) ar[i] = -1;
            else if(ar[i] > 0) ar[i] = 1;
        }
        insert(1 , 0 , n - 1);
        while(q--)
        {
            sf(" %c %d %d" , &ch , &a , &b);
            if(ch == 'C')
            {
                if(b > 0) b = 1;
                else if(b < 0) b = -1;
                updet(1 , 0 , n - 1 , a - 1 , b);
            }
            if(ch == 'P')
            {
                a = queary(1 , 0 , n - 1 , a - 1 , b - 1);
                if(a == 0) pf("0");
                else if(a < 0) pf("-");
                else pf("+");
            }
        }
        pf("\n");
    }
    return 0;
}
