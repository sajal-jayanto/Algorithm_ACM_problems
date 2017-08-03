#include<stdio.h>
#include<math.h>
int main()
{
	unsigned long int num,sum1;
	double sum;
	while(scanf("%ld",&num) && num!=0)
	{
		sum1 = sqrt(num);
		sum = sqrt(num);
		if(sum1 == sum )
		{
			printf("yes\n");
		}
		else printf("no\n");
	}
	return 0;
}
