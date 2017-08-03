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

bool sive[10000010];

void is_prime()
{
    int k = sqrt(10000010);
    for(int i = 4 ; i < 10000010 ; i = i + 2) sive[i] = true;
    for(int i = 3 ; i < k ; i = i + 2)
    {
        if(!sive[i]) for(int j = i * i ; j < 10000010 ; j = j + (2 * i) ) sive[j] = true;
    }
    sive[0] = true;
    sive[1] = true;
}


int main()
{
    //freopen("input.txt" , "r" , stdin);
    is_prime();
    int t , len , lim , num , ans , cnt ;
    char str[10] , s[10];
    set < int > se;
    sf("%d" , &t);
    while(t--)
    {
        sf("%s" , str);
        ans = 0;
        len = strlen(str);
        lim = (1 << len) - 1;
        for(int mark = 1 ; mark <= lim ; ++mark)
        {
            cnt = 0;
            for(int i = 0 ; i < len ; ++i) if((mark & (1 << i)) != 0) s[cnt++] = str[i];
            sort(s , s + cnt);
            do
            {
                num = 0;
                for(int i = 0 ; i < cnt ; ++i) num = (num * 10) + (s[i] - '0');
                if(!sive[num] && se.find(num) == se.end()) { ++ans; se.insert(num); }

            } while(next_permutation(s , s + cnt));
        }
        pf("%d\n" , ans);
        se.clear();
    }
    return 0;
}
