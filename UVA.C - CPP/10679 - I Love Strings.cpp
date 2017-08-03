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
#define MAX             100010
#define MAXR            1010
#define MAXC            11

char one[MAX];
char two[MAX];
int mark[MAX];
int len1 , len2;
void prefix();

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t , k , n , cnt, cc = 0;
    bool flag;
    sf("%d", &t);
    getchar();
    while(t--)
    {
        gets(one);
        len1 = strlen(one);
        sf("%d", &n);
        getchar();
        while(n--)
        {
            gets(two);
            len2 = strlen(two);
            prefix();
            k = 0;
            flag = false;
            for(int i = 1 ; i <= len1 ; ++i)
            {
                while(k > 0 && one[i - 1] != two[k]) k = mark[k];
                if(one[i - 1] == two[k]) ++k;
                if(k == len2)
                {
                    flag = true;
                    break;
                }
            }
            if(flag) pf("y\n");
            else pf("n\n");
        }
    }
    return 0;
}


void prefix()
{
    int k = 0;
    mark[1] = 0;
    for(int i = 2 ; i <= len2 ; ++i)
    {
        while(k > 0 && two[k] != two[i - 1]) k = mark[k];
        if(two[k] == two[i -1]) ++k;
        mark[i] = k;
    }
}
