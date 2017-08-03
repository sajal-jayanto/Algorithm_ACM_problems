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

void BFS(int,int,int);

char str[30][30];
int visit[30][30];
int frist[] = {-1,-1,0,1,1,1,0,-1};
int second[] = {0,1,1,1,0,-1,-1,-1};

int main()
{
    //freopen("input.txt","r",stdin);
	int t,cnt, n = 0;
	while(scanf("%d",&t) != EOF)
    {
        for(int i = 0; i < t ; i++)
        {
            for(int j = 0 ; j < t ; j++)
            {
                scanf(" %c",&str[i][j]);
            }
        }
        cnt = 0;
        memset(visit,-1,sizeof(visit));
        for(int i = 0; i < t ; i++)
        {
            for(int j = 0 ; j < t ; j++)
            {
                if(str[i][j] == '1' && visit[i][j] == -1)
                {
                    BFS(i,j,t);
                    cnt++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",++n,cnt);
    }
    return 0;
}

void BFS(int i, int j, int t)
{

    queue < int > Q;
    Q.push(i);
    Q.push(j);

    while(!Q.empty())
    {
        int n = Q.front();
        Q.pop();
        int m = Q.front();
        Q.pop();

        for(int p = 0 ; p < 8 ; p++)
        {
            int k = n + frist[p];
            int l = m + second[p];
            if((k >= 0 && k < t) && (l >= 0 && l < t) && (str[k][l] == '1'))
            {
                if(visit[k][l] == -1)
                {
                    visit[k][l] = 0;
                    Q.push(k);
                    Q.push(l);

                }
            }
        }
    }
}
