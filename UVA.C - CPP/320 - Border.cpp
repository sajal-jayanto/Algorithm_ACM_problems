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

using namespace std;

int main()
{
    int t;
    char str[10000];
    int a , b, cnt = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &a ,&b);
        scanf("%s", str);
        int bord[35][35];
        memset(bord , 0 , sizeof (bord));
        for(int i = 0 ; str[i] != '.'; i++)
        {
            if(str[i] == 'E') bord[a][b - 1] = 1,a++;
            if(str[i] == 'N') bord[a][b] = 1,b++;
            if(str[i] == 'W') bord[a - 1][b] = 1,a--;
            if(str[i] == 'S') bord[a - 1][b - 1] = 1,b--;
        }
        printf("Bitmap #%d\n", ++cnt);
        for(int i = 31 ; i >= 0 ; i--)
        {
            for(int j = 0 ; j < 32 ; j++) if(bord[i][j] == 1) printf("X"); else printf(".");
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
