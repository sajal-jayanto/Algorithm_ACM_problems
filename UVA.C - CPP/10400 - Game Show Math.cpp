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
#define MAXR            32000
#define MAXC            5
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;


///***************************************  END  **********************************************///

int ar[MAX];
int ans , n;
bool flag;
bool DP[MAX][(MAXR * 2) + 2];
void call(int i , int sum , string s);


int main()
{
    int t ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &n);
        for(int i = 0 ; i < n ; ++i) sf("%d", &ar[i]);
        sf("%d" , &ans);
        flag = false;
        mem(DP , false);
        call(1 , ar[0] , to_string(ar[0]));
        if(!flag) pf("NO EXPRESSION");
        pf("\n");
    }
    return 0;
}


void call(int i , int sum , string s)
{
    if(i == n)
    {
        if(sum == ans && !flag)
        {
            pf("%s" , s.c_str() );
            pf("=%d", ans);
            flag = true;
        }
        return ;
    }
    int temp;
    if(sum + ar[i] <= MAXR && sum + ar[i] >= -MAXR)
    {
        temp = sum + ar[i];
        if(!DP[i + 1][temp + MAXR])
        {
            DP[i + 1][temp + MAXR] = true;
            call(i + 1 , temp ,  s + '+' + to_string(ar[i]));
        }
    }
    if(sum - ar[i] <= MAXR && sum - ar[i] >= -MAXR)
    {
        temp = sum - ar[i];
        if(!DP[i + 1][temp + MAXR])
        {
            DP[i + 1][temp + MAXR ] = true;
            call(i + 1 , temp , s + '-' + to_string(ar[i]));
        }
    }
    if(sum * ar[i] <= MAXR && sum * ar[i] >= -MAXR)
    {
        temp = sum * ar[i];
        if(!DP[i + 1][temp + MAXR])
        {
            DP[i + 1][temp + MAXR] = true;
            call(i + 1 , temp , s + '*' + to_string(ar[i]));
        }
    }
   if(ar[i] && sum % ar[i] == 0 && sum / ar[i] <= MAXR && sum / ar[i] >= -MAXR)
   {
        temp = sum / ar[i];
        if(!DP[i + 1][temp + MAXR])
        {
            DP[i + 1][temp + MAXR] = true;
            call(i + 1 , temp , s + '/' + to_string(ar[i]));
        }
   }
}
