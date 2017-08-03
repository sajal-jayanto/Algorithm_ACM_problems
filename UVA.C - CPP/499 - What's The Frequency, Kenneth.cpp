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

#define PI (2 *  acos(0.0))
#define eps 1e-7

using namespace std;

int abc[26];
int ABC[26];

int main()
{
    int n,m;
    char str[1000];
    while(gets(str))
    {
        memset(abc , 0 , sizeof(abc));
        memset(ABC , 0 , sizeof(ABC));
        m = 0;
        for(int i = 0 ; str[i] ; i++)
        {
            if(isupper(str[i]) != 0)
            {
                n = str[i] - 'A';
                ABC[n]++;
                m = max(m , ABC[n]);
            }
            else if (islower(str[i]) != 0)
            {
                n = str[i] - 'a';
                abc[n]++;
                m = max(m , abc[n]);
            }
        }
        for(int i = 0 ; i < 26 ; i++) if(ABC[i] == m) printf("%c",i + 65);
        for(int i = 0 ; i < 26 ; i++) if(abc[i] == m) printf("%c",i + 97);
        printf(" %d\n",m);
    }
    return 0;
}
