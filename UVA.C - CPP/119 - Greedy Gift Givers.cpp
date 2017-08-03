#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#define FOR freopen("input.txt", "r" , stdin)

using namespace std;


int main()
{

    int t, cnt = 0, a , b;
    string n , k;
    map < string , int > mymap;
    vector < string > name;
    while(scanf("%d",&t) == 1)
    {
        if(cnt) printf("\n");
        cnt++;
        for(int i = 0 ; i < t ; i++) { cin >> n ; mymap[n] = 0 ; name.push_back(n); }
        for(int i = 0 ; i < t ; i++)
        {
            cin >> n >> a >> b;
            if(b != 0)
            {
                mymap[n] = mymap[n] - a  + (a % b);
                int m = (a / b);
                while(b--){ cin >> n ; mymap[n] = mymap[n] + m ; }
            }
        }
        for(int i = 0 ; i < t ; i++) printf("%s %d\n", name[i].c_str() , mymap[name[i]]);
        mymap.clear();
        name.clear();
    }
    return 0;
}
