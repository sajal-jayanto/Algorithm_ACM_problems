#include<stdio.h>
#include<math.h>
int main()
{
	double r,n,ch;
	double pi = 2 * acos ( 0.0 );
	while(scanf("%lf %lf",&r,&n)!=EOF)
	{
		ch = r*r*n*sin((2.0*pi)/n)/2; 
		printf("%.3lf\n",ch);
	}
	return 0;
}
