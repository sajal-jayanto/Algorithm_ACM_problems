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

int gcd(int,int);

int main()
{
    char str[50],*p;
    int x,y,t,cnt = 0;
    scanf("%d",&t);
    gets(str);
    while(t--)
    {
        scanf("%s",str);
        x = strtol(str, &p , 2);
        scanf("%s",str);
        y = strtol(str, &p , 2);
        if(gcd(x,y) == 1) printf("Pair #%d: Love is not all you need!\n",++cnt);
        else printf("Pair #%d: All you need is love!\n",++cnt);
    }
    return 0;
}

int gcd(int a , int b)
{
    if(b == 0) return a;
    return gcd(b ,a % b);
}
