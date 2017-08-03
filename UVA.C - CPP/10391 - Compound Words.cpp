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

map < string , int > mymap;
char str[120010][30];

int main()
{
    int n;
    string a,b;
    int len = 0;
    while(gets(str[len]))
    {
        mymap[str[len]]++;
        len++;
    }
    //for(map < string , int >::iterator it = mymap.begin() ; it != mymap.end() ; it++) printf("%s  %d\n",it->first.c_str(), it->second);
    for(int i = 0 ; i < len ; i++)
    {
        n = strlen(str[i]);
        for(int j = 1 ; j < n - 1 ; j++)
        {
            a.clear();b.clear();
            for(int k = 0 ; k < j ; k++) a = a + str[i][k];
            for(int k = j ; k < n ; k++) b = b + str[i][k];
            if(mymap[a] != 0 && mymap[b] != 0)
            {
                printf("%s\n",str[i]);
                break;
            }
           // printf("%s   %s\n",a.c_str() , b.c_str());
        }
    }
    return 0;
}
