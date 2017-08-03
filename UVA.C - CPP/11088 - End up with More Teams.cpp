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

int t , lim , cc = 0;
vector < int > ve;
int DP[(1 << 16) + 2];
int vis[(1 << 16) + 2];

int call(int mark )
{
    if(mark == lim) return 0;
    int temp , &ans = DP[mark];
    if(vis[mark] == cc) return ans;
    ans = 0;
    for(int i = 0 ; i < t ; ++i)
    {
        if((mark & (1 << i)) == 0)
        {
            for(int j = i + 1 ; j < t ; ++j)
            {
                if((mark & (1 << j)) == 0)
                {
                    for(int k = j + 1 ; k < t ; ++k)
                    {
                        if((mark & (1 << k)) == 0)
                        {
                            temp = ve[i] + ve[j] + ve[k] ;
                            if(temp >= 20 ) temp = 1;
                            else temp = 0;
                            ans = max(ans , temp + call( mark | (1 << i) | (1 << j) | (1 << k)));
                        }
                    }
                }
            }
        }
    }
    vis[mark] = cc;
    return ans;
}


int main()
{
    //freopen("input.txt" , "r" , stdin);
    int temp ;
    while(cin >> t && t)
    {
        lim = (1 << t) - 1;
        for(int i = 0 ; i < t ; ++i)
        {
            cin >> temp;
            ve.push_back(temp);
        }
        ++cc;
        cout << "Case " << cc << ": " << call(0) << endl;
        ve.clear();
    }
    return 0;
}
