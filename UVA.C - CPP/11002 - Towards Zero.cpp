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
int t , cc = 0;
vector < vector < int > > ve;
int DP[60][60][1505];
int vis[60][60][1505];

int call(int r , int c , int sum)
{
    if(c < 0 || c >= ve[r].size()) return (1 << 30);
    if(r == 0) return min( abs(sum - ve[0][0]) , abs(sum + ve[0][0]));
    int &ret = DP[r][c][sum];
    if(vis[r][c][sum] == cc) return ret;
    ret = (1 << 30);
    ret = min(ret , call(r - 1 , c , sum + ve[r][c]));
    ret = min(ret , call(r - 1 , c , sum - ve[r][c]));
    if(r < t)
    {
        ret = min(ret , call(r - 1 , c - 1 , sum + ve[r][c]));
        ret = min(ret , call(r - 1 , c - 1 , sum - ve[r][c]));
    }
    else
    {
        ret = min(ret , call(r - 1 , c + 1 , sum + ve[r][c]));
        ret = min(ret , call(r - 1 , c + 1 , sum - ve[r][c]));
    }
    vis[r][c][sum] = cc;
    return ret;
}


int main()
{
    //freopen("input.txt" , "r" , stdin );
    int  cn ;
    vector < int > temp;
    while(cin >> t && t)
    {
        for(int i = 0 ; i < t ; ++i)
        {
            temp.clear();
            for(int j = 0 ; j <= i ; ++j)
            {
                cin >> cn;
                temp.push_back(cn);
            }
            ve.push_back(temp);
        }
        for(int i = t - 1 ; i >= 1 ; --i)
        {
            temp.clear();
            for(int j = 0 ; j < i ; ++j)
            {
                cin >> cn;
                temp.push_back(cn);
            }
            ve.push_back(temp);
        }
        ++cc;
        cn = ve.size() - 1;
        cout << call( cn , 0 , 0) << endl;
        ve.clear();
    }
    return 0;
}
