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

string str[1000];
string p[1000];
string q[1000];
string r[1000];
string s[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);  cout.tie(false);
   // freopen("input.txt" , "r" , stdin);
    int n , m , a,  b , c , d , cnta , cntb , cntc , cntd , temp ;
    while(cin >> n >> m && (n || m))
    {
        a = 0 , b = 0 , c  = 0 , d = 0 ;
        for(int i = 0 ; i < n ; ++i) cin >> str[i];
        for(int i = 0 ; i < m ; ++i)
        {
            cin >> p[i];
            q[i] = p[i];
        }
        for(int i = 0 ; i < m / 2 ; ++i)
        {
            for(int j = i ; j < m - i - 1 ; ++j)
            {
                char saved = q[i][j];
                q[i][j] = q[m - j - 1][i];
                q[m - j - 1][i] = q[m - 1 - i][m - 1 - j];
                q[m - 1 - i][m - 1 - j] = q[j][m - 1 - i];
                q[j][m - 1 - i] = saved;
            }
        }
        for(int i = 0 ; i < m ; ++i) r[i] = q[i];
        for(int i = 0 ; i < m / 2 ; ++i)
        {
            for(int j = i ; j < m - i - 1 ; ++j)
            {
                char saved = r[i][j];
                r[i][j] = r[m - j - 1][i];
                r[m - j - 1][i] = r[m - 1 - i][m - 1 - j];
                r[m - 1 - i][m - 1 - j] = r[j][m - 1 - i];
                r[j][m - 1 - i] = saved;
            }
        }
        for(int i = 0 ; i < m ; ++i) s[i] = r[i];
        for(int i = 0 ; i < m / 2 ; ++i)
        {
            for(int j = i ; j < m - i - 1 ; ++j)
            {
                char saved = s[i][j];
                s[i][j] = s[m - j - 1][i];
                s[m - j - 1][i] = s[m - 1 - i][m - 1 - j];
                s[m - 1 - i][m - 1 - j] = s[j][m - 1 - i];
                s[j][m - 1 - i] = saved;
            }
        }
        temp = (m * m);
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                cnta = 0 ;cntb = 0 ; cntc = 0 ; cntd = 0 ;
                for(int k = 0 ; k < m ; ++k) for(int l = 0 ; l < m ; ++l)
                {
                    if(str[i + k][j + l] == p[k][l]) ++cnta;
                    if(str[i + k][j + l] == q[k][l]) ++cntb;
                    if(str[i + k][j + l] == r[k][l]) ++cntc;
                    if(str[i + k][j + l] == s[k][l]) ++cntd;
                }
                if(cnta == temp) a++;
                if(cntb == temp) b++;
                if(cntc == temp) c++;
                if(cntd == temp) d++;
            }
        }
        cout << a << " " << b << " "  << c << " " << d << endl;
    }
    return 0;
}
