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
bool cmp(int n);
char dic[1010][12];
char str[1000];
int disabc[26];
int haveabc[26];

int main()
{
    int k = 0;
    while(gets(dic[k]))
    {
        if(dic[k][0] == '#') break;
        else k++;
    }
    while(gets(str))
    {
        if(str[0] == '#') break;
        int cnt = 0;
        for(int i = 0 ; str[i] ; i++)
        {
            if(islower(str[i]) != 0)
            {
                haveabc[str[i] - 'a']++;
            }
        }
        for(int i = 0 ; i < k ; i++)
        {
            if(cmp(i) == 1) cnt++;
            memset(disabc, 0, sizeof(disabc));
        }
        memset(haveabc, 0, sizeof(haveabc));
        printf("%d\n",cnt);
    }
    return 0;
}

bool cmp(int n)
{
    int len = strlen(dic[n]);
    for(int i = 0 ; i < len ; i++)
    {
        disabc[dic[n][i] - 'a']++;
    }
    for(int i = 0 ; i < 26 ; i++)
    {
        if(haveabc[i] != 0 || disabc[i] != 0)
        {
            if(haveabc[i] < disabc[i]) return 0;
        }
    }
    return 1;
}


