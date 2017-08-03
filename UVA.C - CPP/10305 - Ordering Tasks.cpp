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
#define MAX 1010
#define MAXP 2147483640
#define F_TO_R freopen("input.txt", "r" , stdin)
#define F_TO_W freopen("output.txt", "w" , stdout)

using namespace std;
vector < int > myvec[MAX];
vector < int > print;
int work[MAX];
queue < int > Q;

int main()
{
    //F_TO_R;
    int node , cnt, a, b;
    while(scanf("%d %d", &node , &cnt) && (node || cnt))
    {
        memset(work , 0 , sizeof(work));
        while(cnt--)
        {
            scanf("%d %d", &a , &b);
            myvec[a].push_back(b);
            work[b]++;
        }
        for(int i = 1 ; i <= node ; i++) if(!work[i]) Q.push(i);
        while(!Q.empty())
        {
            int k = Q.front();
            Q.pop();
            print.push_back(k);
            int len = myvec[k].size();
            for(int i = 0 ; i < len ; i++)
            {
                work[myvec[k][i]]--;
                if(work[myvec[k][i]] == 0) Q.push(myvec[k][i]);
            }
        }
        printf("%d", print[0]);
        for(int i = 1 ; i < print.size() ; i++) printf(" %d", print[i]);
        while(!Q.empty()) Q.pop();
        for(int i = 0 ; i <= node ; i++) myvec[i].clear();
        print.clear();
        printf("\n");
    }
    return 0;
}

