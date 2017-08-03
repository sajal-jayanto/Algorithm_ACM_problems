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

int ans[1000010];

int main()
{
    int mx = 1;
    int num = 1;
    for(int i = 2 ; i < 1000010 ; ++i)
    {
        for(int j = i ; j < 1000010 ; j = j + i) ans[j]++;
        ans[i]++;
    }
    ans[1]++;
    for(int i = 1 ; i < 1000010 ; ++i)
    {
        if(ans[i] >= mx)
        {
            num = i;
            mx = ans[i];
            ans[i] = num;
        }
        ans[i] = num;
    }
    sf("%d" , &num);
    while(num--)
    {
        sf("%d" , &mx);
        pf("%d\n" , ans[mx]);
    }
    return 0;
}
