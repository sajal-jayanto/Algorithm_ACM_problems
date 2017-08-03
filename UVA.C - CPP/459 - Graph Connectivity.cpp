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
#include <sstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#define MAX 30010
#define MAXP 1000
#define F_TO_R freopen("input.txt", "r" , stdin)
#define F_TO_W freopen("output.txt", "w" , stdout)

using namespace std;

map < char , vector < char > > mymap;
map < char , vector < char > >::iterator it;
bool visit[30];
void BFS(char ch);


int main()
{

    int t, cnt;
    char ch;
    char a[10];
    scanf("%d\n", &t);
    while(t--)
    {
        gets(a);
        int x = a[0] - 65;
        for(int i = 0 ; i <= x ; ++i) mymap[i + 65];
        while(gets(a) && a[0] != '\0')
        {
            mymap[a[0]].push_back(a[1]);
            mymap[a[1]].push_back(a[0]);
        }
        cnt = 0;
        memset(visit , false , sizeof(visit));
        for(it = mymap.begin() ; it != mymap.end() ; ++it)
        {
            ch = it->first;
            if(!visit[ch - 'A'])
            {
                cnt++;
                BFS(ch);
            }
        }
        printf("%d\n", cnt);
        if(t) printf("\n");
        mymap.clear();
    }
}


void BFS(char ch)
{
    visit[ch - 'A'] = true;
    queue < char > Q;
    Q.push(ch);
    while(!Q.empty())
    {
        char k = Q.front();
        Q.pop();
        int len = mymap[k].size();
        for(int i = 0 ; i < len ; ++i)
        {
            char l = mymap[k][i];
            if(!visit[l - 'A'])
            {
                visit[l - 'A'] = true;
                Q.push(l);
            }
        }
    }
}
