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
#define MAX             100100
#define MAXR            9598
#define MAXC            10000LL
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;

struct node {
    int a , b;
    node(){}
    node(int x , int y){a = x ; b = y;}
};
vector < node > one;
vector < node > ans;
int DP[31][1010];
bool mark[31][1010];
int call(int in , int time);

int main()
{
    int time , w , n , x , y, flag = 0;
    while(sf("%d %d" , &time , &w) == 2)
    {
        if(flag) pf("\n");
        flag = 1;
        sf("%d" , &n);
        for(int i = 0 ; i < n ; ++i)
        {
            sf("%d %d" , &x , &y);
            x = (x * w) + ((2 * w) * x);
            one.push_back(node(x , y));
        }
        for(int i = 0 ; i < 31 ; ++i) for(int j = 0 ; j < 1010 ; ++j)
        {
            DP[i][j] = -1;
            mark[i][j] = false;
        }
        pf("%d\n" , call(0 , time));
        x = time;
        for(int i = 0 ; i < one.size() ; ++i)
        {
            if(mark[i][x])
            {
                ans.push_back(node(one[i].a / (3 * w) , one[i].b));
                x = x - one[i].a;
            }
        }
        pf("%d\n" , ans.size());
        for(int i = 0 ; i < ans.size() ; ++i) pf("%d %d\n" , ans[i].a , ans[i].b);
        ans.clear();
        one.clear();
    }
    return 0;
}


int call(int in , int time)
{
    if(in >= one.size()) return 0;
    int &ret = DP[in][time];
    if(ret != -1) return ret;
    int a = 0 , b = 0 ;
    if(time - one[in].a >= 0) a = call(in + 1 , time - one[in].a) + one[in].b;
    b = call(in + 1 , time);
    mark[in][time] = (a > b);
    return ret = max(a , b);
}
