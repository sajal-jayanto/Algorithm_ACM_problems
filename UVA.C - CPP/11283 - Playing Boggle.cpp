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
bool vis[5][5];
int dp[5][5];
string st , str[5];
int len ;
bool flag ;
int one[]={1,1,0,-1,-1,-1,0,1}; //8 direction
int two[]={0,1,1,1,0,-1,-1,-1};//8 direction

int back_track(int x , int y , int pos)
{
    int a , b ;
    if(flag) return 1;
    if(pos >= len ) { flag = true; return 1; }
    int ret = 0;
    for(int i = 0 ; i < 8 ; ++i)
    {
        if(flag) return 1;
        a = x + one[i];
        b = y + two[i];
        if(a >= 0 && a < 4 && b >= 0 && b < 4 && !vis[a][b] && st[pos] == str[a][b])
        {
            vis[a][b] = true;
            ret = back_track(a , b , pos + 1);
            if(ret) return 1;
            vis[a][b] = false;
        }
    }
    return 0;
}



int main()
{
    //freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(false);  cout.tie(false);
    int t , n , ans , cc = 0;
    cin >> t ;
    while(t--)
    {
        ans = 0;
        for(int i = 0 ; i < 4 ; ++i) cin >> str[i];
        cin >> n ;
        while(n--)
        {
            cin >> st;
            len = st.size();
            for(int i = 0 ; i < 4 ; ++i)
            {
                for(int j = 0 ; j < 4 ; ++j)
                {
                    if(str[i][j] == st[0])
                    {
                        memset(vis , false , sizeof(vis));
                        memset(dp , -1 , sizeof(dp));
                        vis[i][j] = true;
                        flag = false;
                        if(back_track(i , j , 1 ) == 1)
                        {
                            if(len == 3 || len == 4) ans++;
                            else if(len == 5) ans = ans + 2;
                            else if(len == 6) ans = ans + 3;
                            else if(len == 7) ans = ans + 5;
                            else  ans = ans + 11;
                            i = 5;
                            j = 5;
                        }
                    }
                }
            }
        }
        cout << "Score for Boggle game " << "#" << ++cc << ": " << ans << endl;
    }
    return 0;
}
