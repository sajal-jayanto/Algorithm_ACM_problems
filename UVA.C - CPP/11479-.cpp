#include<stdio.h>
int main()
{
	int t,i=0;
	unsigned long int a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld %ld %ld",&a,&b,&c);
		if(a+b>c && a+c>b && b+c>a)
		{
			if(a==b && b==c)
			{
				printf("Case %d: Equilateral\n",++i);
			}
			else if (a==b||b==c||a==c)
			{
				printf("Case %d: Isosceles\n",++i);
			}
			else if(a!=b && b!=c)
			{
				printf("Case %d: Scalene\n",++i);
			}
		}
		else printf("Case %d: Invalid\n",++i);
	}
	
	return 0;
}
