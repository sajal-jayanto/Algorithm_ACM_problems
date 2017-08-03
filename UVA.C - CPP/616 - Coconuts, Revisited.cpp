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
#define INF             201000
#define sf              scanf
#define pf              printf

int main()
{
    int num , cnt, temp , ans;
    while(sf("%d" , &num) && num != -1)
    {
        ans = 0;
        for(int i = 100 ; i > 1 ; --i)
        {
            temp = num;
            cnt = 0;
            while(temp % i == 1)
            {
                ++cnt;
                --temp;
                temp = temp - (temp / i);
            }
            if(cnt == i && temp % i == 0)
            {
                ans = i;
                break;
            }
        }
        if(ans) pf("%d coconuts, %d people and 1 monkey\n" , num , ans);
        else pf("%d coconuts, no solution\n" , num);
    }
    return 0;
}
