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
#define MAX 15
#define fileR freopen("input.txt", "r" , stdin)

using namespace std;
void print_row(int a , int b);
void print_col(int a , int b);

char bord[MAX][MAX];
int mark[MAX][MAX];
map < int , string > print;
map < int , string >::iterator it;


int main()
{
    //fileR;
    int row , col, cnt, cc = 0;
    while(scanf("%d", &row) && row)
    {
        if(cc) printf("\n");
        scanf("%d",&col);
        memset(mark , 0 , sizeof(mark));
        for(int i = 0 ; i < row ; i++)
            for(int j = 0 ; j < col ; j++)
                scanf(" %c",&bord[i][j]);
         cnt = 0;

        for(int i = 0 ; i < row ; i++)
            for(int j = 0 ; j < col ; j++)
                if(bord[i][j] != '*')
                    if(i == 0 || j == 0) mark[i][j] = ++cnt;
                    else if(bord[i - 1][j] == '*' || bord[i][j - 1] == '*') mark[i][j] = ++cnt;

        printf("puzzle #%d:\n", ++cc);
        printf("Across\n");
        print_row(row , col);
        printf("Down\n");
        print_col(row , col);
    }
    return 0;
}


void print_row(int a , int b)
{
    print.clear();
    string s;
    for(int i = 0 ; i < a ; i++)
    {
        for(int j = 0 ; j < b ; )
        {
            s.clear();
            if(bord[i][j] != '*')
            {
                int x = mark[i][j];
                while(bord[i][j] != '*' && j < b)
                s = s + bord[i][j++];
                print[x] = s;
            }
            else j++;
        }
    }
    for(it = print.begin() ; it != print.end() ; it++) printf("%3d.%s\n", it->first , it->second.c_str());
}

void print_col(int a , int b)
{
    print.clear();
    string s;
    for(int i = 0 ; i < b ; i++)
    {
        for(int j = 0 ; j < a ; )
        {
            s.clear();
            if(bord[j][i] != '*')
            {
                int x = mark[j][i];
                while(bord[j][i] != '*' && j < a )
                s = s + bord[j++][i];
                print[x] = s;
            }
            else j++;
        }
    }
    for(it = print.begin() ; it != print.end() ; it++) printf("%3d.%s\n", it->first , it->second.c_str());
}
