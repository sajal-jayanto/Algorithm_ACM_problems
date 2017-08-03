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
#define MAX 12

using namespace std;

int main()
{
    char str[MAX];
    long long hour , mint , sec , nsec,total;
    while(scanf("%s",str) == 1)
    {
        hour = ((str[0] - 48) * 10) + (str[1] - 48);
        mint = ((str[2] - 48) * 10) + (str[3] - 48);
        sec =  ((str[4] - 48) * 10) + (str[5] - 48);
        nsec = ((str[6] - 48) * 10) + (str[7] - 48);
        total = (hour * 3600) + (mint * 60) + sec;
        total = (total * 100) + nsec;
        total = (total * 125) / 108;
        printf("%07lld\n",total);
    }
    return 0;
}
