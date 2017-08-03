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
#define MAX 55

#define PI (2 *  acos(0.0))
#define eps 1e-7

bool find_it(int,int);

using namespace std;
char str[MAX][MAX];
char ar[MAX];

int main()
{
    //freopen("input.txt","r",stdin);
    int t,row,col,n;
    bool flage;
    scanf("%d",&t);
    while(t--)
    {
        while(getchar() != '\n');
        scanf("%d %d",&row,&col);

        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                scanf(" %c",&str[i][j]);
                str[i][j] = tolower(str[i][j]);
            }
        }
        scanf("%d",&n);
        gets(ar);
        while(n--)
        {
            gets(ar);
            for(int i = 0 ; ar[i] ; i++) ar[i] = tolower(ar[i]);
            flage = false;
            for(int i = 0 ; i < row ; i++)
            {
                for(int j = 0 ; j < col ; j++)
                {
                    if(ar[0] == str[i][j] && find_it(i ,j) == true)
                    {
                        flage = true;
                        printf("%d %d\n",i + 1,j + 1);
                        break;
                    }
                }
                if(flage) break;
            }
        }
        if(t) printf("\n");
    }
    return 0;
}

bool find_it(int i , int j)
{
    int cnt = 2;
    int len = strlen(ar);
    if(len == 1) return true;
    if(str[i][j + 1] == ar[1])
    {
        if(len == 2) return true;
        for(int k = 2 ; k < len ; k++)
        {
            if(str[i][j + k] == ar[k]) cnt++;
            else break;
        }
        if(cnt == len) return true;
    }
    cnt = 2;
    if(str[i][j - 1] == ar[1])
    {
        if(len == 2) return true;
        for(int k = 2 ; k < len ; k++)
        {
            if(str[i][j - k] == ar[k]) cnt++;
            else break;
        }
        if(cnt == len) return true;
    }
    cnt = 2;
    if(str[i + 1][j] == ar[1])
    {
        if(len == 2) return true;
        for(int k = 2 ; k < len ; k++)
        {
            if(str[i + k][j] == ar[k]) cnt++;
            else break;
        }
        if(cnt == len) return true;
    }
    cnt = 2;
    if(str[i - 1][j] == ar[1])
    {
        if(len == 2) return true;
        for(int k = 2 ; k < len ; k++)
        {
            if(str[i - k][j] == ar[k]) cnt++;
            else break;
        }
        if(cnt == len) return true;
    }
    cnt = 2;
    if(str[i + 1][j + 1] == ar[1])
    {
        if(len == 2) return true;
        for(int k = 2 ; k < len ; k++)
        {
            if(str[i + k][j + k] == ar[k]) cnt++;
            else break;
        }
        if(cnt == len) return true;
    }
    cnt = 2;
    if(str[i + 1][j - 1] == ar[1])
    {
        if(len == 2) return true;
        for(int k = 2 ; k < len ; k++)
        {
            if(str[i + k][j - k] == ar[k]) cnt++;
            else break;
        }
        if(cnt == len) return true;
    }
    cnt = 2;
    if(str[i - 1][j + 1] == ar[1])
    {
        if(len == 2) return true;
        for(int k = 2 ; k < len ; k++)
        {
            if(str[i - k][j + k] == ar[k]) cnt++;
            else break;
        }
        if(cnt == len) return true;
    }
    cnt = 2;
    if(str[i - 1][j - 1] == ar[1])
    {
        if(len == 2) return true;
        for(int k = 2 ; k < len ; k++)
        {
            if(str[i - k][j - k] == ar[k]) cnt++;
            else break;
        }
        if(cnt == len) return true;
    }
    return false;
}
