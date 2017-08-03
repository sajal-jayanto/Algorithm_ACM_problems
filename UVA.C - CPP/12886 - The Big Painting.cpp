#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf


unsigned long long H[2010][2];
unsigned long long bord[2010][2010];
const unsigned long long base1 = 10007 , base2 = 10009;
char one[2010][2010];
char two[2010][2010];


unsigned long long hash_(int x , int y , int n , int m)
{
    return bord[x][y] - bord[x - n][y] * H[n][1] - bord[x][y - m] * H[m][0] + bord[x - n][y - m] * H[m][0] * H[n][1];
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int cnt = 0;
    unsigned long long x , y ;
    H[0][0] = H[0][1] = 1;
    for(int i = 1 ; i < 2010 ; ++i)
    {
        H[i][0] = (H[i - 1][0] * base1);
        H[i][1] = (H[i - 1][1] * base2);
    }
    int a , b , r, c;
    while(sf("%d %d %d %d" , &a , &b , &r , &c) == 4)
    {
        for(int i = 0 ; i < a ; ++i) sf("%s" , one[i]);
        for(int i = 0 ; i < r ; ++i) sf("%s" , two[i]);
        x = 0;
        for(int i = 0 ; i < a ; ++i)
        {
            y = 0;
            for(int j = 0 ; j < b ; ++j) y = y * base1 + (one[i][j] == 'x');
            x = x * base2 + y;
        }
        memset(bord , 0 , sizeof(bord));
        for(int i = 0 ; i < r ; ++i)
        {
            y = 0;
            for(int j = 0 ; j < c ; ++j)
            {
                y = y * base1 + (two[i][j] == 'x');
                bord[i + 1][j + 1] = bord[i][j + 1] * base2 + y;
            }
        }
        cnt = 0;
        for(int i = a ; i <= r ; ++i)
        {
            for(int j = b ; j <= c ; ++j)
            {
                if(hash_(i , j , a , b) == x) ++cnt;
            }
        }
        pf("%d\n" , cnt);
    }
    return 0;
}
