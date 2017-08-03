#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
int main()
{
	int row,col;
	while(scanf("%d %d",&row,&col) == 2)
	{
		if(row == 0 && col == 0) break;
		int a = row;
		int b = col;
		if(row > col) swap(row,col);
		if(row == 1) printf("%d knights may be placed on a %d row %d column board.\n",col,a,b);
		else if(row == 2)
		{
			if(col%4 == 1 || col%4 == 3) printf("%d knights may be placed on a %d row %d column board.\n",col+1,a,b);
			else printf("%d knights may be placed on a %d row %d column board.\n",col+col%4,a,b);
		}
		else printf("%d knights may be placed on a %d row %d column board.\n",((col * row + 1)/2),a,b);
	}
	return 0;
}
