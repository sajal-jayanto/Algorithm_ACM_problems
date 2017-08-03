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
#define MAX 30

using namespace std;
int BFS(int a , int j);
vector < string  > bord;
int one[] = {-1,-1,0,1,1,1,0,-1};
int two[] = {0,1,1,1,0,-1,-1,-1};

int main()
{
    //freopen("input.txt" ,"r" , stdin);
    int t;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--)
    {
        string temp;
        while(getline(cin , temp) && !temp.empty()) bord.push_back(temp);
        int cnt = 0;
        int k = bord.size();
        for(int i = 0 ; i < k ; i++)
        {
            int l = bord[i].size();
            for(int j = 0 ; j < l ; j++) if(bord[i][j] == '1') cnt = max(cnt , BFS(i , j));
        }
        printf("%d\n", cnt);
        if(t) printf("\n");
    }
    return 0;
}

int BFS(int a , int b)
{
    int cnt = 1;
    queue < int > Q;
    Q.push(a);
    Q.push(b);
    bord[a][b] = '0';
    while(!Q.empty())
    {
        int k = Q.front();
        Q.pop();
        int l = Q.front();
        Q.pop();
        for(int i = 0 ; i < 8 ; i++)
        {
            int x = k + one[i];
            int y = l + two[i];
            if((x >= 0 && x < bord.size()) && (y >= 0 && y < bord[x].size()) && bord[x][y] == '1')
            {
                bord[x][y] = '0';
                Q.push(x);
                Q.push(y);
                cnt++;
            }
        }
    }
    return cnt ;
}
