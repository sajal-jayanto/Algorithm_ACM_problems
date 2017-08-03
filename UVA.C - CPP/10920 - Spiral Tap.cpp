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


long long gcd(long long a , long long b) {  return !b ? a : gcd(b , a % b);  }

long long mulmod(long long a , long long b , long long c)
{
    long long x, y = a % c;
    while(b > 0)
    {
        if(b % 2 == 1) x = (x + y) % c;
        y = (y * 2) % c;
        b = b / 2 ;
    }
    return x % c;
}



int main()
{
   // freopen("input.txt" , "r" , stdin);
    long long d , num , r , c , nr , nc , odd , temp , total ;
    while(sf("%lld %lld", &d , &num) && (d || num))
    {
        temp = ((d >> 1) + 1);
        if(num == 1)
        {
            pf("Line = %lld, column = %lld.\n" , temp , temp );
            continue ;
        }
        r = c = temp;
        nr =  nc = temp + 1;
        odd = 3;
        for(int i = 1 ; i <= temp ; ++i)
        {
            total = (odd * odd);
            if(num <= total)
            {
                odd = odd - 2;
                total = (odd * odd);
                total++;
                if(total <= num && num <= total + odd) { pf("Line = %lld, column = %lld.\n" , c + 1 , r - (num - total) ); break; }
                total = total + odd;
                if(total <= num && num <= total + odd) { pf("Line = %lld, column = %lld.\n" , r - (num - total) + 1 , c - odd ); break; }
                total = total + odd + 1;
                if(total <= num && num <= total + odd) { pf("Line = %lld, column = %lld.\n" , c - odd , c - odd + (num - total)); break; }
                total = total + odd + 1;
                if(total <= num && num <= total + odd + 1 ) { pf("Line = %lld, column = %lld.\n" , (c + 1 ) - ((total + odd + 1)  - num ), c + 1 ); break; }
            }
            else
            {
                nr++; nc++;
                r++; c++;
                odd = odd + 2;
            }
        }
    }
    return 0;
}
