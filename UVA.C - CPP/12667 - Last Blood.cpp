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

int trak[105];
int how[105];
int mem[105][105];

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int a , b , n , t , k;
    char ch ;
    string temp;
    memset(trak, -1 , sizeof(trak));
    cin >> n >> t >> k;
    while(k--)
    {
        cin >> a >> b >> ch >> temp;
        if(temp == "Yes")
        {
            if(!mem[ch - 'A'][b] && trak[ch - 'A'] <= a)
            {
                mem[ch - 'A'][b] = 1;
                how[ch - 'A'] = b;
                trak[ch - 'A'] = a;
            }
        }
    }

    for(int i = 0 ; i < n ; ++i)
    {
        if(trak[i] == -1) cout << (char) (i + 65) << " - -" << endl;
        else cout << (char) (i + 65) << " " << trak[i] << " " << how[i] << endl;
    }
    return 0;
}
