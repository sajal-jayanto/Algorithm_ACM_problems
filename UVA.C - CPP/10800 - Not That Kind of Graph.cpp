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
#define MAXR 120
#define MAXC 60

using namespace std;


int cnt[MAXC];
char str[MAXR][MAXC];
char ar[MAXC];

int main()
{
    freopen("output.txt","w",stdout);
    int t,cc = 0;
    scanf("%d",&t);
    gets(ar);
    while(t--)
    {
        scanf("%s",ar);
        int len = strlen(ar);
        int a = len + 63;
        for(int i = 58 - len ; i < a ; i++)
        {
            for(int j = 0 ; j < 60 ; j++)
            {
                str[i][j] = ' ';
            }
        }
        int max = MAXC;
        int min = MAXC;
        int x = MAXC;
        char ch = '?';
        for(int j = 0; j < len ; j++)
		{
			if (ar[j] == 'R')
			{
				if(ch == '/')
				{
					x--;
					if (x < min) min = x;
				}
				ch = '/';

			}
			else if(ar[j] == 'F')
			{
				if(ch == '\\' || ch == '_')
				{
					x++;
					if(x > max) max = x;
				}
				ch = '\\';
			}
			else
			{
				if (ch == '/')
				{
					x--;
					if(x < min)min = x;
				}
				ch = '_';
			}

			cnt[x] = j;
			str[x][j] = ch;
		}
        printf("Case #%d:\n",++cc);

		for(int i = min; i <= max; ++i)
		{
			printf ("| ");
			a = cnt[i];
			for(int j = 0; j <= a ; ++j) printf ("%c",str[i][j]);
			printf("\n");
		}
		printf("+");
		for(int i = -2; i < len ; i++) printf("-");
		printf("\n\n");
    }
    return 0;
}
