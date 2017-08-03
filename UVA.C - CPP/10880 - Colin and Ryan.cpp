#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <iostream>
#include <stack>
#include <deque>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
void do_it(long long,long long);

using namespace std;

vector < long long > myvector;

int main()
{

    int t,count = 0;
    long long c,r;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%lld %lld",&c,&r);
        if(c == r)
        {
            printf("Case #%d: 0\n",++count);
            continue;
        }
        c = c - r;
        do_it(c , r);
        sort(myvector.begin(),myvector.end());
        printf("Case #%d:",++count);
        for(unsigned int i = 0 ; i < myvector.size() ; i++)
        {
            printf(" %lld",myvector.at(i));
        }
        printf("\n");
        myvector.clear();
    }
     return 0;
}

void do_it(long long num , long long r)
{
    int n = sqrt(num);
    for(int i = 1 ; i <= n ; i++)
    {
        if(num % i == 0)
        {
            if(num / i != i)
            {
                if((num / i) > r) myvector.push_back(num / i);
                if(i > r) myvector.push_back(i);
            }
            else
            {
                if(i > r) myvector.push_back(i);
            }
        }
    }
}
