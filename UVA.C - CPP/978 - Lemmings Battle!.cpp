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

priority_queue < int > vectorg,vectorb;

int main()
{
    freopen("input.txt","r",stdin);
    int t;
    int fil,g,b;
    long long sum1,sum2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&fil,&g,&b);
        int n;
        sum1 = sum2 = 0;
        for(int i = 0 ; i < g ; i++)
        {
            scanf("%d",&n);
            sum1 = sum1 + n;
            vectorg.push(n);
        }
        for(int i = 0 ; i < b ; i++)
        {
            scanf("%d",&n);
            sum2 = sum2 + n;
            vectorb.push(n);
        }
        if(sum1 == sum2)
        {
            printf("green and blue died\n");
            if(t) printf("\n");
            continue;
        }
         while ( !vectorb.empty() && !vectorg.empty() ) {
            priority_queue < int > Lb,Lg;
            for ( int i=0; i < fil && !vectorb.empty() && !vectorg.empty(); i++ ) {
                int x=vectorb.top(),y = vectorg.top();
                vectorb.pop(), vectorg.pop();
                int z = x - y;
                if ( z > 0 ) Lb.push(z);
                if ( z < 0 ) Lg.push(-z);
            }
            while ( !Lb.empty() ) { vectorb.push(Lb.top()); Lb.pop(); }
            while ( !Lg.empty() ) { vectorg.push(Lg.top()); Lg.pop(); }
        }
        if(sum1 > sum2)
        {
            printf("green wins\n");
            while ( !vectorg.empty() )
            {
                printf("%d\n",vectorg.top());
                vectorg.pop();
            }
        }
        else
        {
            printf("blue wins\n");
            while ( !vectorb.empty() )
            {
                printf("%d\n",vectorb.top());
                vectorb.pop();
            }
        }
        if(t) printf("\n");
    }
    return 0;
}
