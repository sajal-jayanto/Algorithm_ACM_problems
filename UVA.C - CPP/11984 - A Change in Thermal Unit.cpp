#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
int main()
{
	int t,i;
	double C,F;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lf %lf",&C,&F);
		C = C + ((0.5 * F)/0.9);
		printf("Case %d: %.2lf\n",i,C);  
	}
	return 0;
}
