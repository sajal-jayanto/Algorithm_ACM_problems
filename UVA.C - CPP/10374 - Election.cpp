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

map < string , string > mapstr;
map < string , int > mapcnt;


int main()
{
    //freopen("input.txt","r",stdin);
    string a,b;
    int t,n,m;

    scanf("%d",&t);

    while(t--)
    {
        m = 0;
        scanf("%d",&n);
        while(getchar() != '\n');

        while(n--)
        {
            getline(cin , a);
            getline(cin , b);
            mapstr[a] = b;
        }

        scanf("%d",&n);
        while(getchar() != '\n');

        while(n--)
        {
            getline(cin , a);
            mapcnt[a]++;
            if(m < mapcnt[a])
            {
                m = mapcnt[a];
                b = a;
            }
        }
        int cnt = 0;
        for(map < string , int >::iterator it = mapcnt.begin() ; it != mapcnt.end() ; it++)
        {
           if(it->second == m) cnt++;
        }
        if(cnt == 1) printf("%s\n",mapstr[b].c_str());
        else printf("tie\n");
        mapcnt.clear();
        mapstr.clear();
        if(t) printf("\n");

    }
    return 0;
}

