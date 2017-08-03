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
    //freopen("outpu.txt","w",stdout);
    map<int,int>mymap;
    int t,n,m,num,count;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        count = 0;
        while(n--)
        {
            scanf("%d",&num);
            mymap[num]++;
        }
        while(m--)
        {
            scanf("%d",&num);
            if(mymap[num] != 0) mymap[num]--;
            else count++;
        }
        map<int,int>::iterator i;
        for(i = mymap.begin() ; i != mymap.end() ;i++)
        {
            n = (*i).second;
            if(n > 0) count = count + n;
        }
        printf("%d\n",count);
        mymap.clear();
    }
    return 0;
}



