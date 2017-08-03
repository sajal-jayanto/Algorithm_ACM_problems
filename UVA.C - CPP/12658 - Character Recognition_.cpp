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
  //  freopen("input.txt" , "r" , stdin);
    string temp , str[10];
    int t , cnt = 0;
    cin >> t ;
    for(int i = 0 ; i < 5 ; ++i) cin >> str[i];
    for(int i = 0 ; i < t ; ++i)
    {
        temp = "";
        temp += str[3][cnt++];
        temp += str[3][cnt++];
        temp += str[3][cnt++];
        cnt++;
        if(temp == ".*.") pf("1");
        else if(temp == "*..") pf("2");
        else if(temp == "..*") pf("3");
    }
    pf("\n");
    return 0;
}
