#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#define MAX 10010

using namespace std;

int have[MAX];

int main()
{
    int t;
    while(scanf("%d",&t) && t)
    {
        int a = 0;
        int b = 0;
        for(int i = 0 ; i < t ; i++)
        {
            scanf("%d",&have[i]);
            a = max(0 , a + have[i]);
            b = max(a , b);
        }
        if(b == 0) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n",b);
    }
    return 0;
}
