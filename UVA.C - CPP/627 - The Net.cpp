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
#define MAX 3600
#define fileR freopen("input.txt", "r" , stdin)
#define fileW freopen("output.txt", "w" , stdout)

using namespace std;
map < int , vector < int > > mymap;
map < int , vector < int > > memo;
void BFS(int a , int b);

int main()
{
    //fileR;
    int n;
    vector < int > vec;
    char str[10000], *p;
    while(scanf("%d",&n) == 1)
    {
        getchar();
        while(n--)
        {
            gets(str);

            p = strtok(str , "-");
            while(p != NULL)
            {
                vec.push_back(atoi(p));
                p = strtok(NULL , ",");
            }
            for(int i = 1 ; i < vec.size() ; i++) mymap[vec[0]].push_back(vec[i]);
            vec.clear();
        }
       /* for(map < int , vector < int > >::iterator it = mymap.begin() ; it != mymap.end() ; it++)
        {
            printf("%d->", it->first);
            for(int i = 0 ; i < it->second.size() ;i++) printf("%d ",it->second[i]);
            printf("\n");
        }*/
        printf("-----\n");
        int a , b;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d %d", &a , &b);
            BFS(a , b);
            if(memo[b].empty()) printf("connection impossible\n");
            else
            {
                printf("%d", memo[b][0]);
                for(int i = 1 ; i < memo[b].size() ; i++) printf(" %d", memo[b][i]);
                printf("\n");
            }
        }
        mymap.clear();
    }
    return 0;
}



void BFS(int a , int b)
{
    memo.clear();
    queue < int > Q;
    Q.push(a);
    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        if(x == b) { memo[b].push_back(b); return ;}
        int len = mymap[x].size();
        for(int i = 0 ; i < len ; i++)
        {
            int y = mymap[x][i];
            if(memo[y].empty())
            {
                memo[y] = memo[x];
                memo[y].push_back(x);
                Q.push(y);
            }
        }
    }
}
