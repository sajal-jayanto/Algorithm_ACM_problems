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

using namespace std;

#define F_TO_R          freopen("input.txt", "r" , stdin)
#define _pair(x,y)      make_pair(x,y)
#define INF             (1<<30)
#define sf              scanf
#define pf              printf
#define mem(a,b)        memset(a, b, sizeof(a))
#define fs              first
#define se              second
#define MAX             100100
#define MAXR            9598
#define MAXC            10000LL
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;

map < char , int > mp;
map < char , int > ::iterator it;

int main()
{
    char str[100] , ch ;
    int t , len , cnt, y;
    double ans;
    sf("%d" , &t);
    gets(str);
    while(t--)
    {
        ans = 0.0;
        cnt = 0;
        gets(str);
        len = strlen(str);
        ch = str[0];
        for(int i = 1 ; i < len ; ++i)
        {
            if(isalpha(str[i]))
            {
                if(!cnt) mp[ch]++;
                else mp[ch] = mp[ch] + cnt;
                cnt = 0;
                ch = str[i];
            }
            if(isdigit(str[i])) cnt = (cnt * 10) + (str[i] - '0');
        }
        if(!cnt) mp[ch]++;
        else mp[ch] = mp[ch] + cnt;
        for(it = mp.begin() ; it != mp.end() ; ++it)
        {
            //pf("%c %d\n" , it->fs , it->se);
            if(it->fs == 'C') ans += (it->se * 12.01);
            else if(it->fs == 'H') ans += (it->se * 1.008);
            else if(it->fs == 'O') ans += (it->se * 16.00);
            else if(it->fs == 'N') ans += (it->se* 14.01);
        }
        pf("%.3lf\n" , ans);
        mp.clear();
    }
    return 0;
}
