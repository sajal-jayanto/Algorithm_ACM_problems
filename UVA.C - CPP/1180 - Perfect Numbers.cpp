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
#define MAX 55

#define PI (2 *  acos(0.0))
#define eps 1e-7

using namespace std;

int main()
{

    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d,",&n);

        if(n == 2 || n ==  3 || n == 5 || n == 7 || n == 13 || n == 17 || n == 19) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
