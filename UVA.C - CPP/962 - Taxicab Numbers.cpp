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
#define INF             (1<<28)
#define sf              scanf
#define pf              printf
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             1000010
#define MAXR            1000005
#define MAXC            11

map < int , int > mp;
vector < int > ve;

int main()
{
    int temp , len ;
    for(int i = 1 ; i <= 1002; ++i)
    {
        for(int j = i + 1 ; j <= 1002 ; ++j)
        {
            temp = (i * i * i);
            temp = temp + (j * j * j);
            if(temp >= 1000000010) break;
            mp[temp]++;
            if(mp[temp] == 2) ve.push_back(temp);
        }
    }
    sort(ve.begin() , ve.end());
    mp.clear();
    len = ve.size();
    int a , b ;
    while(sf("%d %d" , &a , &b) != EOF)
    {
        temp = 0;
        for(int i = 0 ; i < len ; ++i)
        {
            if(ve[i] >= a && ve[i] <= (a + b)) { pf("%d\n" , ve[i]); ++temp; }
        }
        if(!temp) pf("None\n");
    }
    return 0;
}
