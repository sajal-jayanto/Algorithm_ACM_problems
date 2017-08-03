#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
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
void BFS(string a , string b, map < string ,vector < string > > temp);

map < string , string > memo;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        map < string , vector < string > > point;
        int n , m;
        string one , two;
        scanf("%d %d",&n , &m);
        while(n--)
        {
            cin >> one  >> two;
            point[one].push_back(two);
            point[two].push_back(one);
        }
        while(m--)
        {
            cin >> one  >> two;
            BFS(one , two , point);
            printf("%s\n",memo[two].c_str());
        }
        if(t) printf("\n");
    }
    return 0;
}

void BFS(string a , string b, map < string ,vector < string > > temp)
{
    memo.clear();
    queue < string > Q;
    Q.push(a);
    while(!Q.empty())
    {
        string k = Q.front();
        Q.pop();
        if(k == b)
        {
            memo[b] = memo[b] + b[0];
            return ;
        }
        int len =  temp[k].size();
        for(int i = 0 ; i < len ; i++)
        {
            string l = temp[k][i];
            if(memo[l].size() == 0)
            {
                memo[l] = memo[k] + k[0];
                Q.push(l);
            }
        }
    }
}
