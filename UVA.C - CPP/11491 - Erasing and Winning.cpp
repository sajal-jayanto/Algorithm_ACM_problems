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

deque < int > Q[10];

int main()
{
   // freopen("input.txt" , "r" , stdin);
    int n , m , k , last ;
    char ch ;
    vector < int > ans;
    while(sf("%d %d" , &n , &m) && (n || m))
    {
        for(int i = 1 ; i <= n ; ++i)
        {
            sf(" %c", &ch);
            Q[ch - '0'].push_back(i);
        }
        k = (n - m);
        last = -1;
        for(int i = k - 1 ; i >= 0 ; i--)
        {
            for(int j = 9 ; j >= 0 ; --j)
            {
                if(!Q[j].empty())
                {
                    while(!Q[j].empty() && Q[j].front() < last) Q[j].pop_front();
                    if(last < Q[j].front() && Q[j].front() + i <= n)
                    {
                        last = Q[j].front();
                        ans.push_back(j);
                        Q[j].pop_front();
                        break ;
                    }
                }
            }
        }
        for(auto x : ans) pf("%d", x);
        ans.clear();
        for(int i = 0 ; i < 10 ; ++i) Q[i].clear();
        pf("\n");
    }
}
