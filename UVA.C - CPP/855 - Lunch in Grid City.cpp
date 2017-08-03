#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <sstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#define MAX 50010
#define MAXP 1000
#define F_TO_R freopen("input.txt", "r" , stdin)
#define F_TO_W freopen("output.txt", "w" , stdout)

using namespace std;

int main()
{
    int ar[MAX] ,sr[MAX];
    int t, a, b , n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &a , &b , &n);
        for(int i = 0 ; i < n ; ++i) scanf("%d %d", &ar[i] , &sr[i]);
        sort(ar , ar + n);
        sort(sr , sr + n);
        if(n % 2) n = n / 2;
        else n = (n - 1) / 2;
        printf("(Street: %d, Avenue: %d)\n", ar[n] , sr[n]);
    }
    return 0;
}


