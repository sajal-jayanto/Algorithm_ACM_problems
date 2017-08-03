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
#define MAX 10

using namespace std;
void back_traking(int x ,int  y , int cnt , int  n ,int  m);
char bord[MAX][MAX];
char save[] = {'I','E','H','O','V','A','#'};
string temp;

int main()
{
    int t,n,m;
    int x , y;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                scanf(" %c",&bord[i][j]);
                if(bord[i][j] == '@') x = i , y = j;
            }
        }
        back_traking(x , y , 0 , n , m);
        printf("%s\n",temp.c_str());
        temp.clear();
    }
    return 0;
}

void back_traking(int x ,int  y , int cnt , int  n ,int  m)
{

    if(cnt >= 8) return;
    else if(x - 1 >= 0 && bord[x - 1][y] == save[cnt])
    {
        if(cnt == 0) temp = temp + "forth";
        else temp = temp + " forth";
        back_traking(x - 1 , y , cnt + 1 , n , m);
    }
    else if(y + 1 < 8 && bord[x][y + 1] == save[cnt])
    {
        if(cnt == 0) temp = temp + "right";
        else temp = temp + " right";
        back_traking(x , y + 1 , cnt + 1 , n , m);
    }
    else if(y - 1 >= 0 && bord[x][y - 1] == save[cnt])
    {
        if(cnt == 0) temp = temp + "left";
        else temp = temp + " left";
        back_traking(x , y - 1 , cnt + 1 , n , m);
    }
}


