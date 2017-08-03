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


template < class T > string toString(T n) { ostringstream ost; ost << n; ost.flush() ; return ost.str(); }



long long count_ans(long long num)
{
    long long ans = 0;
    long long dig = 1;
    long long now = 1;
    while(true)
    {
        if(now * 10 > num)
        {
            ans = ans + (num - now + 1) * dig ;
            break;
        }
        ans = ans + (now * 9 * dig);
        now = now * 10;
        dig++;
    }
    return ans ;
}



int main()
{
    //freopen("input.txt" , "r" , stdin );
    long long num , low , high , mid , temp ;
    string str;
    while(sf("%lld" , &num) == 1)
    {
        if(num <= 9)
        {
            pf("%lld\n", num);
            continue ;
        }
        low = 0 , high = 100000000000LL;
        while(low <= high)
        {
            mid = (low + high) >> 1;
            temp = count_ans(mid);
            if( temp <= num) low = mid + 1;
            else high = mid - 1;
        }
        if(temp == num) pf("%lld\n" , mid % 10);
        else if(temp < num)
        {
            str = toString(mid + 1);
            temp++;
            for(int i = 0 ; str[i] ; ++i)
            {
                if(temp == num)
                {
                    pf("%c\n" , str[i]);
                    break ;
                }
                ++temp;
            }
        }
        else if(temp > num)
        {
            str = toString(mid - 1) + toString(mid) ;
            for(int i = str.size() - 1 ; i >= 0 ; --i)
            {
                if(temp == num)
                {
                    pf("%c\n" , str[i]);
                    break ;
                }
                temp--;
            }
        }
    }
    return 0;
}
