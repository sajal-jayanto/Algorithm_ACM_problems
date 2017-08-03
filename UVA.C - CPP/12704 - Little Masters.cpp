#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int t,x,y,r;
	double defolt,small,big;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&x,&y,&r);
		defolt = sqrt(pow(x,2)+pow(y,2));
		small = r - defolt;
		big = r + defolt;
		printf("%.2lf %.2lf\n",small,big);	
	}
	return 0;
}
