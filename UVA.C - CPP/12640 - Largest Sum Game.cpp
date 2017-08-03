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
#define MAX 100010


using namespace std;

char str[5 * MAX];
int num[MAX];

int main()
{
    //freopen("input.txt","r",stdin);
    char *p;
    int k, have , got;
    while(gets(str))
    {
        k = 0;
        p = strtok(str," ");
        while(p != NULL)
        {
            num[k++] = atoi(p);
            p = strtok(NULL , " ");
        }
        have = got = 0;
        for(int i = 0 ; i < k ; i++)
        {
            have = max(0 , have + num[i]);
            got = max(got , have);
        }
        printf("%d\n",got);
    }
    return 0;
}
