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


int num[1000010];
int mem[1000010];


int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t , n , m , k , cnt , pos , ans , cc = 0;
    sf("%d" , &t);
    while(t--)
    {
        ans = (1 << 30);
        sf("%d %d %d" , &n , &m , &k);
        num[1] = 1;
        num[2] = 2;
        num[3] = 3;
        for(int i = 4 ; i <= n ; ++i) num[i] = (num[i - 3] + num[i - 2] + num[i - 1]) % m + 1;
        memset(mem , 0 , sizeof(mem));
        cnt = 0 , pos = 1;
        for(int i = 1 ; i <= n ; ++i)
        {
            mem[num[i]]++;
            if(mem[num[i]] == 1 && num[i] <= k) ++cnt;
            while(mem[num[pos]] > 1 || num[pos] > k)
            {
                mem[num[pos]]--;
                pos++;
            }
            if(cnt == k) ans = min(ans , i - pos + 1);
        }
        if(ans == (1 << 30)) pf("Case %d: sequence nai\n", ++cc);
        else pf("Case %d: %d\n" , ++cc, ans );
    }
    return 0;
}
