#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#define MAX 10

using namespace std;
int visit[MAX][MAX];
int x[]={-2,-1, 1, 2, 2,1,-1,-2};
int y[]={-1,-2,-2,-1, 1,2, 2, 1};
void BFS(int a1 , int a2, int b1 , int b2);
int cnt[MAX][MAX];

int main()
{
    map < char , int > mymap;
    mymap['a'] = 1;mymap['b'] = 2;
    mymap['c'] = 3;mymap['d'] = 4;
    mymap['e'] = 5;mymap['f'] = 6;
    mymap['g'] = 7;mymap['h'] = 8;
    char a[5],b[5];
    while(scanf("%s %s",a,b) == 2)
    {
        int a1 = mymap[ a[0] ];
        int a2 = a[1] - 48;
        int b1 = mymap[ b[0] ];
        int b2 = b[1] - 48;
        BFS(a1,a2,b1,b2);
        printf("To get from %s to %s takes %d knight moves.\n",a,b,cnt[b1][b2]);
    }
    return 0;
}

void BFS(int a1 , int a2, int b1 , int b2)
{
    memset(visit , -1 , sizeof(visit));
    memset(cnt , 0 , sizeof(cnt));
    queue < int > Q;
    Q.push(a1);
    Q.push(a2);
    cnt[a1][a2] = 0;
    while(!Q.empty())
    {
        int n = Q.front();
        Q.pop();
        int m = Q.front();
        Q.pop();
        if(n == b1 && m == b2) return ;
        for(int i = 0 ; i < 8 ; i++)
        {
            int o = n + x[i];
            int p = m + y[i];
            if((o >= 1 && o < 9) && (p >= 1 && p < 9) && visit[o][p] == -1)
            {
                visit[o][p] = 1;
                cnt[o][p] = cnt[n][m] + 1;
                Q.push(o);
                Q.push(p);
            }
        }
    }
}
