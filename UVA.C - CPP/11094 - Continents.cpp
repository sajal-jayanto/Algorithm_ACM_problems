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

using namespace std;

#define F_TO_R          freopen("input.txt", "r" , stdin)
#define _pair(x,y)      make_pair(x,y)
#define INF             (1<<30)
#define sf              scanf
#define pf              printf
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             105
#define MAXR            1000005
#define MAXC            11
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;

//int  big_mod(int n , int  p , int m)
//{
//    int sum;
//    if(!p) return 1;
//    if(p % 2 == 0) { sum = big_mod(n  , p / 2 , m); return ((sum % m ) *(sum % m)) % m; }
//    else return (( n % m) * (big_mod( n , p - 1 , m) % m ))% m;
//}

int one[] ={-1 , 1 , 0 , 0};
int two[] ={ 0 , 0 ,-1 , 1};

///***************************************  END  **********************************************///


void move(int x , int y);
int bord[MAX][MAX];
int row , col , cnt ;
char ch;
int main()
{
    //freopen("input.txt" , "r" , stdin);
    int a , b , mx;
    while(sf("%d %d", &row , &col) == 2)
    {
        mx = 0;
        for(int i = 1 ; i <= row ; ++i) for(int j = 1 ; j <= col ; ++j) sf(" %c", &bord[i][j]);
        sf("%d %d", &a , &b);
        ++a , ++b;
        ch = bord[a][b];
        move(a , b);
        for(int i = 1 ; i <= row ; ++i) for(int j = 1 ; j <= col ; ++j)
        {
            cnt = 0;
            if(bord[i][j] == ch) move(i , j);
            mx = max(mx , cnt);
        }
        pf("%d\n" , mx);
    }
    return 0;
}


void move(int x , int y)
{
    if(bord[x][y] != ch) return ;
    ++cnt;
    bord[x][y] = 0;
    move(x + 1 , y);
    move(x - 1 , y);
    move(x , y % col + 1);
    move(x , (y - 2 + col) % col + 1);
}
