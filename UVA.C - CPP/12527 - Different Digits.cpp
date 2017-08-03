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

map<int,int>mymap;
int have(int);

int main()
{
    int a, b,sum;
    while(scanf("%d %d",&a,&b) == 2)
    {
        sum = 0;
        for(int i = a ; i <= b ; i++)
        {
            sum = sum + have(i);
        }
        printf("%d\n",sum);
    }
    return 0;
}

int have(int num)
{
    mymap.clear();
    while(num)
    {
        int n = num % 10;
        num = num / 10;
        mymap[n]++;
        if(mymap[n] == 2) return 0;
    }
    return 1;
}
