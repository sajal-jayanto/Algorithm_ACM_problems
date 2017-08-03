#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define PI (2 *  acos(0.0))
#define eps 1e-7
#define sf scanf
#define pf printf
#define ab(a) (((a) > 0) ? (a) : -(a))

using namespace std;


long long gcd(long long a , long long b) {  return !b ? a : gcd(b , a % b);  }
int n , cc = 0;
int DP[8][8][8][8][5][4][5][4];

int call(int a , int b , int c , int d , int first , int hfirst , int who , int how)
{
    if(!a && !b && !c && !d)
    {
        if(first != who && hfirst != how) return 1;
        return 0;
    }
    int lim ;
    int &ret = DP[a][b][c][d][first][hfirst][who][how];
    if(ret != 0) return ret;
    ret = 0;
    if(who == 0)
    {
        if(a){
            lim = min(a , 3);
            for(int i = 1 ; i <= lim ; ++i) ret = ret + call(a - i , b , c, d , 1 , i , 1 , i);
        }if(b) {
            lim = min(b , 3);
            for(int i = 1 ; i <= lim ; ++i) ret = ret + call(a , b - i , c, d , 2 , i , 2 , i);
        }if(c){
            lim = min(c , 3);
            for(int i = 1 ; i <= lim ; ++i) ret = ret + call(a , b , c - i, d , 3 , i , 3 , i);
        }if(d){
            lim = min(d , 3);
            for(int i = 1 ; i <= lim ; ++i) ret = ret + call(a , b , c, d - i , 4 , i , 4 , i);
        }
    }
    else
    {
        if(a && who != 1){
            lim = min(a , 3);
            for(int i = 1 ; i <= lim ; ++i) if(how != i) ret = ret + call(a - i , b , c, d, first , hfirst , 1 , i);
        }if(b && who != 2) {
            lim = min(b , 3);
            for(int i = 1 ; i <= lim ; ++i) if(how != i) ret = ret + call(a , b - i , c, d, first , hfirst , 2 , i);
        }if(c && who != 3){
            lim = min(c , 3);
            for(int i = 1 ; i <= lim ; ++i) if(how != i) ret = ret + call(a , b , c - i , d, first , hfirst , 3 , i);
        }if(d && who != 4){
            lim = min(d , 3);
            for(int i = 1 ; i <= lim ; ++i) if(how != i) ret = ret + call(a , b , c, d - i , first , hfirst , 4 , i);
        }
    }
    return ret;
}


int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t , num[4] , sum ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &n);
        sum = 0;
        memset(num , 0, sizeof(num));
        for(int i = 0 ; i < n ; ++i) { sf("%d" , &num[i]); sum += num[i]; }
        if(n == 1)
        {
            if(num[0] <= 3) pf("1\n");
            else pf("0\n");
            continue ;
        }
        else if(sum == 0)
        {
            pf("1\n");
            continue ;
        }
        ++cc;
        pf("%d\n", call(num[0] , num[1] , num[2] , num[3] , 0 , 0 , 0 , 0));
    }
    return 0;
}
