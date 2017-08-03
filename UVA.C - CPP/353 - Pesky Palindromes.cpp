#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#define MAXR 120
#define MAXC 60

using namespace std;

bool is_plinrom(string);

int main()
{
    map < string , int > mymap;
    string s,sub;
    int cnt;
    while(cin >> s)
    {
        cnt = 0;
        mymap.clear();
        int len = s.length();
        for(int i = 0 ; i < len ; i++)
        {
            for(int j = 0 ; j < len ; j++)
            {
                sub = s.substr( i , len - j);
                if(mymap[sub] != 0) continue ;
                mymap[sub]++;
                if(is_plinrom(sub)) cnt++;
            }
        }
        printf("The string '%s' contains %d palindromes.\n",s.c_str(),cnt);
    }
    return 0;
}

bool is_plinrom(string a)
{
    int len = a.length() - 1;
    for(int i = 0 ; i <= len ; i++)
    {
        if(a[i] != a[len - i]) return false;
    }
    return true;
}
