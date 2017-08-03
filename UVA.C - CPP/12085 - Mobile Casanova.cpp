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

void print(int,int);

using namespace std;

int main()
{
   // freopen("input.txt","r",stdin);
    queue < int > Q;
    int t,num,a,b,count = 0;
    while(scanf("%d",&t) && t)
    {
        printf("Case %d:\n",++count);
        while(t--)
        {
            scanf("%d",&num);
            if(Q.empty()) Q.push(num);
            else if(Q.back() + 1 == num)
            {
                Q.push(num);
            }
            else
            {
                if(Q.size() == 1)
                {
                     printf("0%d\n",Q.front());
                     Q.pop();
                     Q.push(num);
                     continue;
                }
                a = Q.front();
                b = Q.back();
                print(a,b);
                while(!Q.empty()) Q.pop();
                Q.push(num);
            }
        }
        if(!Q.empty())
        {
            if(Q.size() == 1)
            {
                printf("0%d\n",Q.front());
                Q.pop();
            }
            else
            {
                a = Q.front();
                b = Q.back();
                print(a,b);
            }
        }
        while(!Q.empty()) Q.pop();
        printf("\n");
    }

    return 0;
}

void print(int a, int b)
{
    string s;
    printf("0%d-",a);
    while(a || b)
    {
        if((a % 10) != (b % 10))
        {
            char ch = (b % 10) + 48;
             s = s + ch;
        }
        a = a / 10;
        b = b / 10;
    }
    for(int i = s.length() - 1 ; i >= 0 ; i--) printf("%c",s.at(i));
    printf("\n");
}
