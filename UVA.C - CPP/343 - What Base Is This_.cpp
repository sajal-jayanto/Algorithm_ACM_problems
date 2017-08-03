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
#define MAX             105
#define MAXR            1000005
#define MAXC            11
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int u_int;

//int  big_mod(int n , int  p , int m)
//{
//    int sum;
//    if(!p) return 1;
//    if(p % 2 == 0) { sum = big_mod(n  , p / 2 , m); return ((sum % m ) *(sum % m)) % m; }
//    else return (( n % m) * (big_mod( n , p - 1 , m) % m ))% m;
//}



///***************************************  END  **********************************************///

vector < long long > one;
vector < long long > two;
int valu(char ch);

int main()
{
   // freopen("input.txt" , "r" , stdin);
    //freopen("output.txt" , "w" , stdout);
    string a , b;
    int mxa , mxb , len1 , len2;
    long long temp;
    while(cin >> a >> b)
    {
        mxa = 0 ; mxb = 0;
        len1 = a.length();
        len2 = b.length();
        for(int i = 0 ; i < len1 ; ++i) mxa = max(mxa , valu(a[i]) + 1);
        for(int i = 0 ; i < len2 ; ++i) mxb = max(mxb , valu(b[i]) + 1);
        for(int i = mxa ; i <= 36 ; ++i)
        {
            temp = 0;
            for(int j = 0 ; j < len1 ; ++j) temp = temp * i + valu(a[j]);
            one.push_back(temp);
        }
        for(int i = mxb ; i <= 36 ; ++i)
        {
            temp = 0;
            for(int j = 0 ; j < len2 ; ++j) temp = temp * i + valu(b[j]);
            two.push_back(temp);
        }
        len1 = one.size();
        len2 = two.size();
        temp = 0;
        for(int i = 0 ; i < len1 ; ++i)
        {
            for(int j = 0 ; j < len2 ; ++j)
            {
                if(one[i] == two[j])
                {
                    temp = 1;
                    mxa = i + mxa;
                    if(mxa < 2) mxa = 2;
                    mxb = j + mxb;
                    if(mxb < 2) mxb = 2;
                    pf("%s (base %d) = %s (base %d)\n", a.c_str() , mxa , b.c_str(), mxb);
                }
                if(temp) break;
            }
            if(temp) break;
        }
        if(!temp) pf("%s is not equal to %s in any base 2..36\n", a.c_str() , b.c_str());
        one.clear();
        two.clear();
    }
    return 0;
}



int valu(char ch)
{
    if(ch >= '0' && ch <= '9') return ch - '0';
    if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 10;
}

