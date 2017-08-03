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
    vector < string > list;
    string a;
    int t,n;
    bool flage;
    scanf("%d",&t);
    while(t--)
    {
        list.clear();
        scanf("%d",&n);
        while(n--)
        {
            cin >> a;
            list.push_back(a);
        }
        sort(list.begin() , list.end());
        flage = false;
        for(int i = 0 ; i < list.size() - 1; i++)
        {
            if(list[i + 1].size() >= list[i].size())
            {
                a = list[i + 1].substr(0, list[i].size());
                if(a == list[i])
                {
                    flage = true;
                    break;
                }
            }
        }
        if(flage) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
