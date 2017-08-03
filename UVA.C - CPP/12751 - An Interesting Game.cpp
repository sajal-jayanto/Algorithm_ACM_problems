#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    int a , b ,c , t, sum ,cc = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&c);
        sum = 0;
        for(int i = 0 ; i < b ; i++) sum = sum + c++;
        printf("Case %d: %d\n",++cc, ((a * (a + 1)) / 2) - sum);
    }
    return 0;
}
