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


int main()
{
    //freopen("input.txt" , "r" , stdin);
    string str;
    int t , dig[10] , len , total , temp , cc = 0;
    bool ans ;
    cin >> t;
    while(t--)
    {
        cin >> str;
        len = str.size();
        total = 0;
        memset(dig , 0 , sizeof(dig));
        for(int i = 0 ; i < len ; ++i)
        {
            total = total + (str[i] - '0');
            dig[str[i] - '0']++;
        }
        ans = true;
        temp = dig[3] + dig[6] + dig[9];
        if(total % 3 == 0 ) { if(temp % 2 == 0) ans = false; }
        else if(total % 3 == 1)
        {
            if(dig[1] || dig[4] || dig[7]) { if(temp % 2) ans = false; }
            else ans = false;
        }
        else
        {
            if(dig[2] || dig[5] || dig[8]) { if(temp % 2) ans = false; }
            else ans = false;
        }
        if(ans) cout << "Case " << ++cc << ": S" << endl;
        else cout << "Case " << ++cc << ": T" << endl;
    }
    return 0;
}
