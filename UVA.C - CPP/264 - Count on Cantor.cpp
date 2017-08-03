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

using namespace std;

int main()
{
    int n, v, d, a, b;
    while(scanf("%d", &n) != EOF)
    {
        v = n;
        for(d = 1; v > d; d++) v -= d;
        if(d % 2) a = 1 + d - v;
        else a = v;
        b = d - a + 1;
        printf("TERM %d IS %d/%d\n", n, a, b);
    }
    return 0;
}
