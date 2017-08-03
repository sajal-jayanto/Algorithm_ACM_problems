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
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#define MAX 15
#define fileR freopen("input.txt", "r" , stdin)

using namespace std;


int main()
{
    int t, a , b;
    char ch;
    scanf("%d", &t);
    while(t--)
    {
        scanf(" %c %d %d", &ch , &a , &b);
        int ans ;
        if(ch == 'Q' || ch == 'r') ans = min(a , b);
        else if(ch == 'k') ans = (((a * b) + 1) / 2);
        else ans = (((a + 1) / 2) * ((b + 1) / 2));
        printf("%d\n", ans);
    }

    return 0;
}
