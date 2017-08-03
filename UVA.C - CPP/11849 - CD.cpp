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
map<int ,int >mymap;


int main()
{
    int m,n,num,count;
	while(scanf("%d %d",&m,&n) && (m || n))
    {
        count = 0;
        for(int i = 0 ; i < m ; i++)
        {
            scanf("%d",&num);
            mymap[num]++;
        }
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d",&num);
            if(mymap[num] != 0) count++;
        }
        printf("%d\n",count);
        mymap.clear();
    }
    return 0;
}
