#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	double a,b,c,e,f;
	while(scanf("%lf %lf %lf",&a,&b,&c) == 3)
	{
		if(a <= 0 || b <= 0 || c <= 0) 
		{
			printf("The radius of the round table is: 0.000\n");
		}
		else
		{
			e = (a + b + c) / 2;
			f = (sqrt(e * (e - a) *(e - b) * (e - c))) / e;
			printf("The radius of the round table is: %.3lf\n",f);	
		}	
	}
	return 0;
}
