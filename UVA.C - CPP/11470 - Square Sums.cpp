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
#define MAX 12
#define MAXP 2147483640
#define fileR freopen("input.txt", "r" , stdin)
#define fileW freopen("output.txt", "w" , stdout)

using namespace std;
int bord[MAX][MAX];

int main()
{
    //fileR;
    int t, cnt = 0;
    while(scanf("%d", &t) && t)
    {
        for(int i = 0 ; i < t ; i++)
            for(int j = 0 ; j < t ; j++)
                scanf("%d", &bord[i][j]);

        int a = 0, b = 0;
        int x = t - 1 , y = t - 1;
        long long sum;
        printf("Case %d:", ++cnt);
        while(a < t || b < t)
        {
            sum = 0;
            for(int i = a ; i < t ; i++) if(bord[a][i] != MAXP){ sum = sum + bord[a][i]; bord[a][i] = MAXP ;}
            for(int i = b ; i < t ; i++) if(bord[i][b] != MAXP){ sum = sum + bord[i][b]; bord[i][b] = MAXP ;}
            for(int i = a ; i < t ; i++) if(bord[i][x] != MAXP){ sum = sum + bord[i][x]; bord[i][x] = MAXP ;}
            for(int i = b ; i < t ; i++) if(bord[y][i] != MAXP){ sum = sum + bord[y][i]; bord[y][i] = MAXP ;}
            a++; b++;
            x--; y--;
            if(sum != 0 ) printf(" %lld", sum);
        }
        printf("\n");
    }
    return 0;
}
