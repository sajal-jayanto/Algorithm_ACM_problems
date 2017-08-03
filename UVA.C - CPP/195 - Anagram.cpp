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

bool cmp(char a , char b)
{
    if(tolower(a) == tolower(b)) return a < b;
    return tolower(a) < tolower(b);
}

int main()
{
    char ar[500];
    int t;
    scanf("%d",&t);
    gets(ar);
    while(t--)
    {
        gets(ar);
        int len = strlen(ar);
        sort (ar , ar + len, cmp);
        printf("%s\n",ar);
        while(next_permutation(ar, ar + len , cmp))
        {
            printf("%s\n",ar);
        }
    }
    return 0;
}

