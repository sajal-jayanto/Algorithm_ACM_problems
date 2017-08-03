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

using namespace std;

int visit[30];
vector < int > myvector[30];
void DFS(int a);
int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t, cnt , c ;
    char ch , a[5];
    scanf("%d\n",&t);
    while(t--)
    {
        c = 0;
        gets(a);
        cnt = a[0] - 'A';
        for(int i = 0 ; i <= cnt ; i++){ myvector[i].clear(); visit[i] = 0;}
        while(gets(a) && a[0] != '\0'){ myvector[a[0] -'A'].push_back(a[1] - 'A'); myvector[a[1] -'A'].push_back(a[0] - 'A');}
        for(int i = 0 ; i <= cnt ; i++) if(visit[i] == 0){ DFS(i) ; c++;}
        printf("%d\n",c);
        if(t) printf("\n");
    }
    return 0;
}


void DFS(int a)
{
    visit[a] = 1;
    for(int i = 0 ; i < myvector[a].size() ; i++)
    {
        if(visit[myvector[a][i]] == 0) DFS(myvector[a][i]);
    }
    return ;
}
