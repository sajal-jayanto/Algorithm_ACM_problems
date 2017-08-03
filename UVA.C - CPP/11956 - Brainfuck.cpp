#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define PI (2 *  acos(0.0))
#define eps 1e-7
#define MAX 1000010

using namespace std;

char str[MAX];
int num[110];

int main()
{
    //freopen("input.txt","r",stdin);
    int t,cnt = 0;
    scanf("%d",&t);
    gets(str);
    while(t--)
    {
        memset(num , 0 , sizeof(num));
        gets(str);
        int n = 0;
        for(int i = 0 ; str[i] ; i++)
        {
            if(str[i] == '>')
            {
                n++;
                if(n == 100) n = 0;
            }
            else if(str[i] == '<')
            {
                n--;
                if(n == -1) n = 99;
            }
            else if(str[i] == '+')
            {
                num[n]++;
                if(num[n] == 256) num[n] = 0;
            }
            else if(str[i] == '-')
            {
                num[n]--;
                if(num[n] == -1) num[n] = 255;
            }
        }
        printf("Case %d:",++cnt);
        for(int i = 0 ; i < 100 ; i++)
        {
            printf(" %02X",num[i]);
        }
        printf("\n");
    }
    return 0;
}
