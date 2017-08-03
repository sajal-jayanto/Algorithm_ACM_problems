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
#define MAX 6

using namespace std;

char bord[MAX][MAX];
int x, y;
int upgreat(char ch);

int main()
{
    //freopen("input.txt", "r", stdin);
	char ch;
	int cc = 0;
	while(true)
    {
        int ans = 0;
        for (int i = 0; i < 5; i++)
        {
            for(int j = 0 ; j < 5 ; j++)
            {
                scanf("%c",&bord[i][j]);
                if(bord[0][0] == 'Z') return 0;
                if(bord[i][j] == ' ') x = i , y = j;
            }
            getchar();
        }
        while(ch = getchar())
        {
            if(ch == '0')
            {
                getchar();
                 break;
            }
            else ans += upgreat(ch);
        }
        if(cc != 0) printf("\n");
        printf("Puzzle #%d:\n",++cc);
        if(ans != 0) printf("This puzzle has no final configuration.\n");
        else
        {
            for(int i = 0 ; i < 5 ; i++)
            {
                printf("%c",bord[i][0]);
                for(int j = 1 ; j < 5 ; j++) printf(" %c",bord[i][j]);
                printf("\n");
            }
        }
    }
}

int upgreat(char ch)
{
	if (ch == 'A')
	{
        if(x - 1 >= 0) { swap(bord[x - 1][y] , bord[x][y]); x--; return 0 ;}
        else return 1;
	}
	else if (ch == 'B')
	{
	    if(x + 1 < 5) { swap(bord[x + 1][y] , bord[x][y]); x++; return 0 ;}
	    else return 1;
	}
	else if (ch == 'R')
	{
	     if(y + 1 < 5) { swap(bord[x][y + 1] , bord[x][y]); y++; return 0 ;}
	     else return 1;
	}
	else if(ch == 'L')
	{
	    if(y - 1 >= 0) { swap(bord[x][y - 1] , bord[x][y]); y--; return 0 ;}
	    else return 1;
	}
	else if(ch == '\n') return 0;
	else return 1;
}

