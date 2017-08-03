#include <map>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    int t,n;
    long long num,sum;
    char s[20]; string g;
    scanf("%d %d",&t,&n);
    gets(s);
    map < string , int > mymap;
    while(t--)
    {
        scanf("%s %lld",s,&num);
        g = s;
        mymap[g] = num;
    }
    while(n--)
    {
        sum = 0;
        while(scanf("%s",s) == 1)
        {
            if(s[0] == '.') break;
            g = s;
            if(mymap[g] != 0)
            {
                sum = sum + mymap[g];
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
