#include<stdio.h>
int main()
{
	//freopen ("output.txt","w",stdout);
	int n;
	while(scanf("%d",&n) && n!=0)
	{
		n = n%10;
		if(n==1||n==4||n==6||n==9)
		{
			printf("0.40\n");
		}
		if(n==2||n==3||n==7||n==8)
		{
			printf("0.20\n");
		}
		if(n==5||n==0)
		{
			printf("0.00\n");
		}
	}
	return 0;
}
