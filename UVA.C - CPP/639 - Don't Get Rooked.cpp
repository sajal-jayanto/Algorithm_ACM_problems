#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

char bord[5][5];
int mark[5][5];
int t;

void put(int a , int b)
{
    mark[a][b] = 1;
    for(int i = a + 1 ; i < t ; ++i)
    {
        if(bord[i][b] == 'X') break;
        mark[i][b]++;
    }
    for(int i = a - 1 ; i >= 0 ; --i)
    {
        if(bord[i][b] == 'X') break;
        mark[i][b]++;
    }
    for(int i = b + 1 ; i < t ; ++i)
    {
        if(bord[a][i] == 'X') break;
        mark[a][i]++;
    }
    for(int i = b - 1 ; i >= 0 ; --i)
    {
        if(bord[a][i] == 'X') break;
        mark[a][i]++;
    }
}

void unput(int a , int b)
{
    mark[a][b] = 0;
    for(int i = a + 1 ; i < t ; ++i)
    {
        if(bord[i][b] == 'X') break;
        mark[i][b]--;
    }
    for(int i = a - 1 ; i >= 0 ; --i)
    {
        if(bord[i][b] == 'X') break;
        mark[i][b]--;
    }
    for(int i = b + 1 ; i < t ; ++i)
    {
        if(bord[a][i] == 'X') break;
        mark[a][i]--;
    }
    for(int i = b - 1 ; i >= 0 ; --i)
    {
        if(bord[a][i] == 'X') break;
        mark[a][i]--;
    }
}



int call(int take)
{
    int ret = take;
    for(int i = 0 ; i < t ; ++i) for(int j = 0 ; j < t ; ++j)
    {
        if(bord[i][j] == '.' && mark[i][j] == 0)
        {
            put(i , j);
            ret = max(ret , call(take + 1));
            unput(i , j);
        }
    }
    return ret;
}

int main()
{
   // freopen("input.txt" , "r" , stdin);
    while(cin >> t && t)
    {
        memset(mark , 0 , sizeof(mark));
        for(int i = 0 ; i < t ; ++i) for(int j = 0 ;  j < t ; ++j) cin >> bord[i][j];
        cout << call(0) << endl;
    }
    return 0;
}
