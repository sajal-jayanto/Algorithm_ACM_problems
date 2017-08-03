#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>

#define PI (2 *  acos(0.0))
#define eps 1e-7
#define sf scanf
#define pf printf
#define ab(a) (((a) > 0) ? (a) : -(a))

using namespace std;

int n , m , cc = 0;
long long DP[35][35][35][3];
int vis[35][35][35][3];

long long call(int a , int b , int cnt , int flag)
{
    if(a == n) return 1;
    if(b == n) return 0;
    long long &ret = DP[a][b][cnt][flag];
    if(vis[a][b][cnt][flag] == cc) return ret;
    ret = 0;
    if(!flag)
    {
        if(cnt < m) ret = ret + call(a + 1 , b , cnt + 1 , flag);
        ret = ret + call(a , b + 1 , 1 , !flag);
    }
    else
    {
        if(cnt < m) ret = ret + call(a , b + 1 , cnt + 1 , flag);
        ret = ret + call(a + 1 , b , 1 , !flag);
    }
    vis[a][b][cnt][flag] = cc;
    return ret;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    while(sf("%d %d" , &n , &m) && (n != -1 || m != -1))
    {
        pf("Case %d: ", ++cc);
        if(n == 0 || m == 0)
        {
            if(m == 0) pf("0\n");
            else pf("1\n");
        }
        else pf("%lld\n", call(1 , 0 , 1 , 0) * 2);
    }
    return 0;
}
