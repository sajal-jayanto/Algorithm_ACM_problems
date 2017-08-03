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

vector < string > ve;

int main()
{
    //freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false);
    cout.tie(false);  cin.tie(false);
    int t , n , q , x;
    string temp;
    cin >> n ;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> temp;
        ve.push_back(temp);
    }
    cin >> q;
    while(q--)
    {
        cin >> x ;
        x--;
        if(ve[x] != "?") cout << ve[x] << endl;
        else
        {
            bool lh = false , rh = false;
            int left = 0 , right = 0;
            for(int i = x ; i >= 0 ; i--)
            {
                if(ve[i] != "?")
                {
                    lh = true;
                    break;
                }
                ++left;
            }
            for(int i = x ; i < n ; i++)
            {
                if(ve[i] != "?")
                {
                    rh = true;
                    break;
                }
                ++right;
            }
            if(lh && rh)
            {
                if(left == right) cout << "middle of " << ve[x - left] << " and " << ve[x + right] << endl;
                else if(left > right)
                {
                    temp = ve[x + right];
                    while(right--) cout << "left of " ;
                    cout << temp << endl;
                }
                else
                {
                    temp = ve[x - left];
                    while(left--) cout << "right of " ;
                    cout << temp << endl;
                }
            }
            else
            {
                if(rh)
                {
                    temp = ve[x + right];
                    while(right--) cout << "left of " ;
                    cout << temp << endl;
                }
                else
                {
                    temp = ve[x - left];
                    while(left--) cout << "right of " ;
                    cout << temp << endl;
                }
            }
        }
    }
    return 0;
}
