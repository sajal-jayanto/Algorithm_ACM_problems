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

int joseph(int a , int b)
{
    if(a == 1) return 0;
    return ((joseph(a - 1 , b) + b) % a);
}


int main()
{
    //freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(false);  cout.tie(false);
    int a , b , t , cc = 0;
    cin >> t ;
    while(t--)
    {
        cin >> a >> b ;
        cout << "Case " << ++cc << ": " << joseph(a , b) + 1 << endl;
    }
    return 0;
}
