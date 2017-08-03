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

#define MAX 2000

#define PI (2 *  acos(0.0))
#define eps 1e-7


using namespace std;


int main()
{
	int row,col,count;
	while(scanf("%d %d",&row,&col) == 2)
	{
		char name[row + 1][col + 1];
		char temp[col + 1];
		while(getchar() != '\n');
		gets(name[0]);
		for(int i = 1 ; i < row ; i++)
		{
			gets(temp);
			count = 0;
			for(int j = 0 ; j < col ; j++)
			{
				if(name[0][j] != temp[j]) count++;
			}
			strcpy(name[count],temp);
		}
		for(int i = 0 ; i < row ; i++) printf("%s\n",name[i]);
	}
	return 0;
}