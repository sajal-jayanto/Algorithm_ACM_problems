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
#define MAX 10000

#define PI (2 *  acos(0.0))
#define eps 1e-7


using namespace std;

int main()
{
    char ch,*p;
    string s;
    int n = 0;
    char str[10000];
    map < string , vector < int > > mymap;
    ch = getchar();
    gets(str);
    while(gets(str))
    {
        n++;
        p = strtok(str , " ,.!?_-:;");
        while(p != NULL)
        {
            s = p;
            if(s.at(0) == ch)
            {
                if(mymap[s].empty()) mymap[s].push_back(n);
                else if(mymap[s][mymap[s].size() - 1] != n) mymap[s].push_back(n);
            }
            p = strtok(NULL , " ,.!?_-:;");
        }
    }
    for(map < string , vector < int > >::iterator it = mymap.begin() ; it != mymap.end() ; it++)
    {
        printf("%s",it->first.c_str());
        for(int i = 0 ; i < it->second.size() ; i++) printf(" %d",it->second[i]);
        printf("\n");
    }
    return 0;
}

