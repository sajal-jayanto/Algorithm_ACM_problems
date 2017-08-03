#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#define MAX 200

using namespace std;

char n[MAX];
char p[MAX];


int main()
{
    int save[10][4] = {{0},{0},{6,2,4,8},{1,3,9,7},{6,4},{0},{0},{1,7,9,3},{6,8,4,2},{1,9}};
    while(scanf("%s %s",n,p) && (n[0] != '0' || p[0] != '0'))
    {
        int len = strlen(n) - 1;
        if(n[len] == '0' or n[len] == '1' or n[len] == '5' or n[len] == '6') printf("%c\n",n[len]);
        else if(n[len] == '4' or n[len] == '9')
        {
            int k = strlen(p) - 1;
            k = p[k] - 48;
            k = k % 2;
            printf("%d\n",save[n[len] - 48][k]);
        }
        else
        {
            int k = 0;
            for(int i = 0 ; p[i] ; i++)
            {
                k = (k * 10) + (p[i] - 48);
                k = k % 4;
            }
            printf("%d\n",save[n[len] - 48][k]);
        }
    }
    return 0;
}
