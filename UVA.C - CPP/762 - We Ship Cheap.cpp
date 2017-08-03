#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#define MAX 25
#define MAXP 2147483640
#define F_TO_R freopen("input.txt", "r" , stdin)
#define F_TO_W freopen("output.txt", "w" , stdout)

using namespace std;
map < string , vector < string > > mymap;
map < string , vector < string > > memo;
void BFS(string a , string b);

int main()
{
    //F_TO_R;
    int t, cnt = 0;;
    string one , two;
    while(scanf("%d", &t) == 1)
    {
        getchar();
        while(t--)
        {
            cin >> one >> two;
            mymap[one].push_back(two);
            mymap[two].push_back(one);
        }
        if(cnt) printf("\n");
        cin >> one >> two;
        BFS(one , two);
        if(!memo[two].empty())
        {
            for(int i = 0 ; i < memo[two].size() - 1; i++) printf("%s %s\n", memo[two][i].c_str() , memo[two][i + 1].c_str() );
        }
        else printf("No route\n");
        cnt++;
        mymap.clear();
    }
    return 0;
}



void BFS(string a , string b)
{
    memo.clear();
    queue < string > Q;
    Q.push(a);
    while(!Q.empty())
    {
        string k = Q.front();
        Q.pop();
        if(k == b) { memo[b].push_back(b); return ;}
        int len = mymap[k].size();
        for(int i = 0 ; i < len ; i++)
        {

            string l = mymap[k][i];
            if(memo[l].empty())
            {
                memo[l] = memo[k];
                memo[l].push_back(k);
                Q.push(l);
            }
        }
    }
}
