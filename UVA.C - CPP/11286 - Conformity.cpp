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
#include <sstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#define MAX 150
#define MAXP 1000
#define F_TO_R freopen("input.txt", "r" , stdin)
#define F_TO_W freopen("output.txt", "w" , stdout)

using namespace std;

int main()
{
    int t, _max , ans;
    int ar[5];
    char bord[50];
    map < string , int > mymap;
    map < string , int >::iterator it;
    while( scanf("%d", &t) && t)
    {
        while(t--)
        {
            for(int i = 0 ; i < 5 ; ++i) scanf("%d", &ar[i]);
            sort(ar , ar + 5);
            sprintf(bord , "%d%d%d%d%d", ar[0] , ar[1] , ar[2] , ar[3] , ar[4]);
            mymap[bord]++;
        }
        _max = ans = 0;
        for(it = mymap.begin() ; it != mymap.end() ; ++it)
        {
            if(it->second > _max) _max = it->second , ans = 0;
            if(it->second == _max) ans = ans + _max;
        }
        printf("%d\n", ans);
        mymap.clear();
    }

    return 0;
}
