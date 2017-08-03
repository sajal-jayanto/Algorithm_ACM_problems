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
    int s,m,a,b,temp;
    while(scanf("%d %d",&s,&m)  == 2)
    {
        if(s < m)
        {
            a = s;
            b = m;
        }
        else
        {
            a = m;
            b = s;
        }
        while(a)
        {
            temp = a;
            a = b % a;
            b = temp;
        }
        if(b == 1) printf("%10d%10d    Good Choice\n\n",s,m);
        else printf("%10d%10d    Bad Choice\n\n",s,m);
    }
    return 0;
}
