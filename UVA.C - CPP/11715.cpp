#include<stdio.h>
#include<math.h>
int main()
{
	int t,i=0;
	double a,b,c,sum1,sum2;
	while( scanf("%d",&t) && t!=0 )
	{
		scanf("%lf %lf %lf",&a,&b,&c);
		if(t==1)
		{
			sum1 = (b-a)/c;
			sum2 = (a*c+0.5*sum1*pow(c,2));
			printf("Case %d: %.3lf %.3lf\n",++i,sum2,sum1);
		}
		if(t==2)
		{
			sum1 = (b-a)/c;
			sum2 = (a*sum1+0.5*c*pow(sum1,2));
			printf("Case %d: %.3lf %.3lf\n",++i,sum2,sum1);
		}
		if(t==3)
		{
			sum1 = sqrt(pow(a,2)+2*b*c);
			sum2 = (sum1-a)/b;
			printf("Case %d: %.3lf %.3lf\n",++i,sum1,sum2);
		}
		if(t==4)
		{
			sum1 = sqrt(pow(a,2)-2*b*c);	
			sum2 = (a-sum1)/b;
			printf("Case %d: %.3lf %.3lf\n",++i,sum1,sum2);
		}
	}
	
	return 0;
}
