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

int main()
{

    int t,a,b,n;
    int ans[5];
    while(scanf("%d",&t) && t)
    {
       while(t--)
       {    a = b = 0;
            for(int i = 0 ; i < 5 ; i++)
            {
                scanf("%d",&ans[i]);
                if(ans[i] <= 127)
                {
                    a++;
                    n = i;
                }
                else b++;
            }
            if(a == 1 && b == 4) printf("%c\n", n + 65);
            else printf("*\n");
        }
    }
    return 0;
}
