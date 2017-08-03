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

char one[MAX];
int len ;
bool prefix(int l);

int main()
{
   // freopen("tem.txt" , "r" , stdin);
    int t , temp , cnt ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%s" , one);
        len = strlen(one);
        cnt = len;
        temp = sqrt(len);
        for(int i = 1 ; i <= temp ; ++i)
        {
            if(len % i == 0)
            {
                if(i <= (len / 2) && i < cnt && prefix(i)) cnt = i;
                if(i != (len / i) && (len / i) <= (len / 2) && (len / i) < cnt && prefix(len / i)) cnt = len / i;
            }
        }
        pf("%d\n" , cnt);
    }
    return 0;
}

bool prefix(int l)
{
   for(int i = 0 ; i < len ; i = i + l)
   {
        for(int j = 0 ; j < l ; ++j)
        {
            if(one[i + j] != one[j]) return false;
        }
   }
   return true;
}

