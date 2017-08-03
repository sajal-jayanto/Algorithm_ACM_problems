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
#define MAX 1010

using namespace std;

map < string , int > mymap;

char str[MAX];

int main()
{
    freopen("input.txt","r",stdin);
    char *p;
    string s;
    bool flage;
    int cnt,cc = 0;
    while(gets(str))
    {
        cnt = 0;
        flage = false;
        if(str[0] == '\0') flage = true;
        p = strtok(str, " .,?`~!(){}[];:_-");
        while(p != NULL)
        {
            s = p;
            mymap[s]++;
            p = strtok(NULL , " .,?`~!(){}[];:_-@#$%^&\"*|'/");
        }
        gets(str);
        if(str[0] == '\0') flage = true;
        p = strtok(str, " .,?`~!(){}[];:_-@#$%^&\"*|'/");
        while(p != NULL)
        {
            s = p;
            if(mymap[s] != 0) cnt++;
            p = strtok(NULL , " .,?`~!(){}[];:_-@#$%^&\"*|'/" );
        }
        if(flage) printf("%2d. Blank!\n",++cc);
        else printf("%2d. Length of longest match: %d\n",++cc,cnt);
        mymap.clear();
    }
    return 0;
}
