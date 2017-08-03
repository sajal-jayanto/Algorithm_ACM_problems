#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <stack>
#include <deque>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    map <string,int> mymap;
    int t,n,d,count = 0;
    string s;
    char ar[25];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s %d",ar,&d);
            s = ar;
            mymap[s] = d;
        }
        scanf("%d %s",&d,ar);
        s = ar;
        if(mymap[s] == 0)
        {
            printf("Case %d: Do your own homework!\n",++count);
            continue;
        }
        if(mymap[s] <= d) printf("Case %d: Yesss\n",++count);
        else if(mymap[s] <= d + 5) printf("Case %d: Late\n",++count);
        else  printf("Case %d: Do your own homework!\n",++count);
        mymap.clear();

    }

    return 0;
}
