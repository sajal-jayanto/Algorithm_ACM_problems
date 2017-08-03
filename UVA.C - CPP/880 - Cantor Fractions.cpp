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
void find_it(long long n);

int main()
{
    long long num;
    while(scanf("%lld",&num) == 1) find_it(num);
    return 0;
}
void find_it(long long n)
{
    n = n * 2 ;
    long long x = (long long) sqrt(n);
    if(x * (x + 1) < n) x++;
    n = n / 2;
    long long y = n - x * (x - 1) / 2;
    x = x + 1 - y;
    printf("%lld/%lld\n",x,y);
}
