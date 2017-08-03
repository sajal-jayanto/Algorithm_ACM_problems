#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#define MAX 100010
#define sf scanf
#define pf printf

using namespace std;

typedef long long ll;
ll mod = 1000000009ll;

struct matrix {

    ll ar[3][3];
};


matrix matrix_mul(matrix  a , matrix b);
matrix matrix_expo(matrix a , ll p);

int main()
{
    ll num , ans;
    matrix temp;
    while(sf("%lld" , &num) && num)
    {
        if(num == 1)
        {
            pf("0\n");
            continue;
        }
        if(num == 2)
        {
            pf("1\n");
            continue;
        }
        if(num == 3)
        {
            pf("2\n");
            continue;
        }
        if(num == 4)
        {
            pf("3\n");
            continue;
        }
        temp.ar[0][0] = 1; temp.ar[0][1] = 1; temp.ar[0][2] = 1;
        temp.ar[1][0] = 1; temp.ar[1][1] = 0; temp.ar[1][2] = 0;
        temp.ar[2][0] = 0; temp.ar[2][1] = 1; temp.ar[2][2] = 0;
        temp = matrix_expo(temp , num - 3);
        ans = ((temp.ar[0][0] * 2) % mod + temp.ar[0][1]) % mod;
        pf("%lld\n", ans);
    }
    return 0;
}



matrix matrix_expo(matrix a , ll p)
{
    if(p == 1) return a;
    if(p % 2) return matrix_mul(a , matrix_expo(a , p - 1));
    matrix ret = matrix_expo(a , p >> 1);
    return matrix_mul(ret , ret);
}



matrix matrix_mul(matrix  a , matrix b)
{
    matrix ret;
    ll sum;
    for(int i = 0 ; i < 3 ; ++i)
    {
        for(int j = 0 ; j < 3 ; ++j)
        {
            sum = 0;
            for(int k = 0 ; k < 3 ; ++k) sum = sum + ((a.ar[i][k] % mod) * (b.ar[k][j] % mod)) % mod;
            ret.ar[i][j] = (sum % mod);
        }
    }
    return ret;
}
