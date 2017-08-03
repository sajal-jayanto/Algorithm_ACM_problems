#include <stdio.h>
int main()
{
	int t,a,b,sum,sum2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		sum = a+b;
		sum2 = a-b;
		if(sum>=0 && sum2>=0 && sum%2==0 && sum2%2==0 )
		{
			printf("%d %d\n",sum/2,sum2/2);
		}
		else printf("impossible\n");
	}
	return 0;
}
