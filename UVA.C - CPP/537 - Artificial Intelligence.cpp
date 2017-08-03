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
#define MAX 10

using namespace std;

char str[100000];


int main()
{
    int t, cnt = 0;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        double U,I,P;
        U = -1;
        I = -1;
        P = -1;
        for(int i = 0 ;  ; i++)
        {
            str[i] = getchar();
            if(str[i] == '\n') break;
            if(str[i] == '=')
            {
                if(str[i - 1] == 'U')
                {
                    scanf("%lf", &U);
                    if (str[i] == 'm') U = U * 0.001;
                    else if (str[i] == 'k') U = U * 1000.0;
                    else if (str[i] == 'M') U = U * 1000000.0;
                }
                else if(str[i - 1] == 'I')
                {
                    scanf("%lf", &I);
                    str[i] = getchar();
                    if (str[i] == 'm') I = I * 0.001;
                    else if (str[i] == 'k') I = I * 1000.0;
                    else if (str[i] == 'M') I = I * 1000000.0;
                }
                else if(str[i - 1] == 'P')
                {
                    scanf("%lf", &P);
                    str[i] = getchar();
                    if (str[i] == 'm') P = P  * 0.001;
                    else if (str[i] == 'k') P = P * 1000.0;
                    else if (str[i] == 'M') P = P * 1000000.0;
                }
            }
        }
        printf("Problem #%d\n",++cnt);
        if(P == -1) printf("P=%.2lfW\n",U * I);
        else if(I == -1) printf("I=%.2lfA\n",  P / U );
        else printf("U=%.2lfV\n" ,P / I );
        printf("\n");
    }
    return 0;

}
