#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,d,area;
	while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
	{
		d=(a+b+c)/2;
		a=(d-a);
		b=(d-b);
		c=(d-c);
		area=sqrt(d*a*b*c);
		area= area*1.333333333;
		if(area<=0)
		{
			printf("-1.000\n");
		}
		else printf("%.3lf\n",area);
	}
	return 0;
}
