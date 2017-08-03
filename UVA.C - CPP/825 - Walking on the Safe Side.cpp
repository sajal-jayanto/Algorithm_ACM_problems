#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

bool bord[500][500];
int DP[500][500];
vector < int > temp;
char str[100000];
int row , col ;


int call(int x , int y)
{
    if(x >= row || y >= col) return 0;
    if(x == row - 1 && y == col - 1) return 1;
    int &ret = DP[x][y];
    if(ret != -1) return ret;
    ret = 0;
    if(bord[x][y] == false)
    {
        ret = ret + call(x + 1 , y);
        ret = ret + call(x , y + 1);
    }
    return ret;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t ;
    char *p;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d %d" , &row , &col);
        gets(str);
        for(int i = 0 ; i < row ; ++i)
        {
            gets(str);
            p = strtok(str , " " );
            while(p != NULL)
            {
                temp.push_back(atoi(p));
                p = strtok(NULL , " " );
            }
            for(int i = 1 ; i < temp.size() ; ++i) bord[temp[0] - 1][temp[i] - 1] = true;
            temp.clear();
        }
        memset(DP , -1 , sizeof(DP));
        pf("%d\n" , call(0 , 0));
        memset(bord , false , sizeof(bord));
        if(t) pf("\n");
    }
    return 0;
}
