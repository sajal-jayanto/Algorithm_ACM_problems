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
#define MAX 5000010

#define PI (2 *  acos(0.0))
#define eps 1e-7

using namespace std;

int main()
{
    //freopen("output.txt","w",stdout);
	int s,len;
	char num[20];
	while(scanf("%d %s",&s,num) == 2)
	{
		len = strlen(num);
		if(s == 0 && len == 1 && num[0] == '0') break;

		for(int i = 0 ; i < len ; i++)
		{
			printf(" ");
			if(num[i] == '1' || num[i] == '4')
			{
				for(int j = 0 ; j < s ; j++) printf(" ");
			}
			else for(int j = 0 ; j < s ; j++) printf("-");
			if(i != len - 1) printf("  ");
			else printf(" ");
		}
		printf("\n");
		for(int i = 0 ; i < s ; i++)
        {
            for(int j = 0 ; j < len ; j++)
            {
                if(num[j] == '1'||num[j] == '2' || num[j] == '3'||num[j] == '7')
                {
                    printf(" ");
                    for(int k = 0 ; k < s ; k++) printf(" ");
                    printf("|");
                    if(j != len - 1) printf(" ");
                }
                else if(num[j] == '6' || num[j] == '5')
                {
                    printf("|");
                    for(int k = 0 ; k < s ; k++) printf(" ");
                    printf(" ");
                    if(j != len - 1) printf(" ");
                }
                else
                {
                    printf("|");
                    for(int k = 0 ; k < s ; k++) printf(" ");
                    printf("|");
                    if(j != len - 1) printf(" ");
                }
            }
            printf("\n");
        }
        for(int i = 0 ; i < len ; i++)
		{
			printf(" ");
			if(num[i] == '0' || num[i] == '1' || num[i] == '7')
			{
				for(int j = 0 ; j < s ; j++) printf(" ");
			}
			else for(int j = 0 ; j < s ; j++) printf("-");
			if(i != len - 1) printf("  ");
			else printf(" ");
		}
		printf("\n");
		for(int i = 0 ; i < s ; i++)
        {
            for(int j = 0 ; j < len ; j++)
            {
                if(num[j] == '1'|| num[j] == '3' || num[j] == '4'|| num[j] == '5'|| num[j] == '7'|| num[j] == '9')
                {
                    printf(" ");
                    for(int k = 0 ; k < s ; k++) printf(" ");
                    printf("|");
                    if(j != len - 1) printf(" ");
                }
                else if(num[j] == '2')
                {
                    printf("|");
                    for(int k = 0 ; k < s ; k++) printf(" ");
                    printf(" ");
                    if(j != len - 1) printf(" ");
                }
                else
                {
                    printf("|");
                    for(int k = 0 ; k < s ; k++) printf(" ");
                    printf("|");
                    if(j != len - 1) printf(" ");
                }
            }
            printf("\n");
        }
        for(int i = 0 ; i < len ; i++)
		{
			printf(" ");
			if(num[i] == '1' || num[i] == '4' || num[i] == '7')
			{
				for(int j = 0 ; j < s ; j++) printf(" ");
			}
			else for(int j = 0 ; j < s ; j++) printf("-");
			if(i != len - 1) printf("  ");
			else printf(" ");
		}
		printf("\n\n");
	}
	return 0;
}
