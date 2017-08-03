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

string str;

bool is_palindrome(int a , int b)
{
    while(a < b)
    {
        if(str[a] != str[b]) return false;
        a++; b--;
    }
    return true;
}


int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t , len ;
    bool flag ;
    cin >> t;
    while(t--)
    {
        flag = false;
        cin >> str;
        len = str.size() - 1;
        for(int i = 0 ; i < len ; ++i)
        {
            if(is_palindrome(0 , i ) && is_palindrome(i + 1 , len))  flag = true , i = len;
        }
        if(flag) cout << "alindrome" << endl;
        else if(is_palindrome(0 , len)) cout << "palindrome" << endl;
        else cout << "simple" << endl;
     }
    return 0;
}
