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

using namespace std;

map < string , int > mymap;

char str[1001000];

int main()
{

    int t,m;
    string s,n;
    while(cin >> t >> str)
    {
        int len = strlen(str) - (t - 1);
        m = 0;
        for(int i = 0 ; i < len ; i++)
        {
            s.clear();
            for(int j = i ; j < i + t ; j++) s = s + str[j];
            mymap[s]++;
            if(mymap[s] > m)
            {
                m = mymap[s];
                n = s;
            }
        }
       cout << n << "\n" ;
    }
    return 0;
}
