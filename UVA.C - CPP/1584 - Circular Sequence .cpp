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

using namespace std;

#define MAX 10010


int main()
{
   // freopen("input.txt" , "r" , stdin);
   ios_base::sync_with_stdio(false);
   cout.tie(false);  cin.tie(false);
    int t  , len ;
    char ch ;
    string str , two , temp;
    cin >> t ;
    while(t--)
    {
        cin >> str;
        len = str.size();
        ch = str[0];
        for(int i = 1 ; i < len ; ++i) ch = min(ch , str[i]);
        two.clear();
        two = str + str;
        for(int i = 0 ; i < len ; ++i)
        {
            if(two[i] == ch)
            {
                temp.clear();
                temp = two.substr(i  , len);
                str = min(str , temp);
            }
        }
        cout << str << endl;
    }
    return 0;
}
