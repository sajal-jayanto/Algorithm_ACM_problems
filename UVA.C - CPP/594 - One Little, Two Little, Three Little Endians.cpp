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

using namespace std;
long long convart(string s);
int main()
{

    long long num;
    string s;
    int k;
    while(scanf("%lld",&num) == 1)
    {
        for(int i = 7; i >= 0 ; i--)
        {
           k = num >> i;
           if(k & 1) s = s + "1";
           else s = s + "0";
        }
        for(int i = 15 ; i >= 8 ; i--)
        {
           k = num >> i;
           if(k & 1) s = s + "1";
           else s = s + "0";
        }
        for(int i = 23; i >= 16 ; i--)
        {
           k = num >> i;
           if(k & 1) s = s + "1";
           else s = s + "0";
        }
        for(int i = 31 ; i >= 24 ; i--)
        {
           k = num >> i;
           if(k & 1) s = s + "1";
           else s = s + "0";
        }
        printf("%lld converts to %lld\n",num,convart(s));
        s.clear();
    }
    return 0;
}

long long convart(string s)
{
    long long ans = 0;
    int c = 1;
    for(int i = 31; i >= 0 ; i--)
    {
        ans = ans + ((s.at(i) - 48) * c);
        c = c * 2;
    }
    return ans;
}
