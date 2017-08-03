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
#define MAX 50010

using namespace std;

long long sum[MAX];

int main()
{
    sum[1] = 1;
    for(long long i = 2 ; i < MAX ; i++) sum[i] = sum[i - 1] + (i * i * i);
    int n;
    while(scanf("%d",&n) != EOF) printf("%lld\n",sum[n]);

    return 0;
}
