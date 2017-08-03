#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    multiset<long long> myset;
    multiset<long long>::iterator i;
    long long t,num,ans,n,max,min;
    while(scanf("%lld",&t) && t)
    {
        ans = 0;
        while(t--)
        {
            scanf("%lld",&n);
            while(n--)
            {
                scanf("%lld",&num);
                myset.insert(num);
            }
            if(!myset.empty())
            {
                i = myset.begin();
                min = (*i);
                myset.erase(i);
                if(!myset.empty())
                {
                    i = myset.end();
                    i--;
                    max = (*i);
                    myset.erase(i);
                }
                ans = ans + (max - min);
            }
        }
        printf("%lld\n",ans);
        myset.clear();
    }
    return 0;
}
