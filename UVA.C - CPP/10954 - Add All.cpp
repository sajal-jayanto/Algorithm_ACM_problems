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
#define MAX 105
#define MAXP 1000
#define F_TO_R freopen("input.txt", "r" , stdin)
#define F_TO_W freopen("output.txt", "w" , stdout)

using namespace std;

int main()
{
    priority_queue < int > Q;
    int t, temp;
    while( scanf("%d", &t) && t)
    {
        for(int i = 0 ; i < t ; ++i)
        {
            scanf("%d", &temp);
            Q.push(-temp);
        }
        int sum = 0;
        while(Q.size() != 1)
        {
            int a = Q.top() * -1;
            Q.pop();
            int b = Q.top() * -1;
            Q.pop();
            a = a + b;
            sum = sum + a;
            Q.push(-a);
        }
        printf("%d\n", sum);
        while(!Q.empty()) Q.pop();
    }
    return 0;
}
