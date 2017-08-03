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

    int t,n,c = 0,count;
    char a[200];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %s",&n,a);
        count = 0;
        for(int i = 0 ; i < n ;)
        {
            if(a[i] == '#') i++;
            else
            {
                count++;
                i = i + 3;
            }
        }
        printf("Case %d: %d\n",++c,count);
    }
    return 0;
}
