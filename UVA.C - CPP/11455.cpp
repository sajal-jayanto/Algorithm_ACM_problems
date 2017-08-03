#include <stdio.h>
int main()
{
	int t,a,b,c,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if( a==b && b==c && c==d )
		{
			printf("square\n");
		}
		else if ((a==b && c==d)||(a==c && b==d)||(a==d &&b==c))
		{
			printf("rectangle\n");
		}
		else if(a+b+c>d && a+b+d>c && a+d+c>b && b+c+d>a)
		{
			printf("quadrangle\n");
		}
		else printf("banana\n");
	}
	return 0;
}
