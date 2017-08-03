#include <bits/stdc++.h>

using namespace std;

#define sf  scanf
#define pf  printf

struct matrix {

   int ar[42][42];
};
matrix one;
int n ;
int mod ;

matrix matrix_mul(matrix a , matrix b)
{
    int sum ;
    matrix ret;
    for(int i = 0 ; i < n ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
        {
            sum = 0;
            for(int k = 0 ; k < n ; ++k)
            {
                sum = sum + (a.ar[i][k] * b.ar[k][j]) % mod;
            }
            ret.ar[i][j] = sum % mod;
        }
    }
    return ret;
}

matrix matrix_add(matrix a , matrix b)
{
    matrix ret;
    for(int i = 0 ; i < n ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
        {
            ret.ar[i][j] = (a.ar[i][j] + b.ar[i][j]) % mod;
        }
    }
    return ret;
}

matrix matrix_expo(matrix temp , int p)
{
    if(p == 1) return temp;
    if(p & 1) return matrix_mul(temp , matrix_expo(temp , p - 1));
    else
    {
        matrix ret = matrix_expo(temp , p / 2);
        return matrix_mul(ret , ret);
    }
}

matrix call(matrix temp , int p)
{
    if(p == 1) return temp;
    if(p == 0) return one;
    matrix ret = one;
    ret = matrix_mul( matrix_add(ret , matrix_expo(temp , p / 2) )  , call(temp , p / 2));
    if(p & 1) ret = matrix_add(ret , matrix_expo(temp , p));
    return ret;
}


int main()
{
   // freopen("tem.txt" , "r" , stdin);
    memset(one.ar , 0 , sizeof(one));
    for(int i = 0 ; i < 42 ; ++i) one.ar[i][i] = 1;
    mod = 10ll;
    matrix temp , ans ;
    long long p ;
    while(sf("%d %lld" , &n , &p) && n)
    {
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                sf("%d" , &temp.ar[i][j]);
                temp.ar[i][j] = temp.ar[i][j] % mod;
            }
        }
        ans = call(temp , p);
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if(j == 0) pf("%d" , ans.ar[i][j]);
                else pf(" %d" , ans.ar[i][j]);
            }
            pf("\n");
        }
        pf("\n");
    }
    return 0;
}
