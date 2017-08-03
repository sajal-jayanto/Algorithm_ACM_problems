#include<stdio.h>
#include<math.h>
int main()
{
	int t,a,b,temp,money;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&a,&b,&money);
		printf("%d\n",money*(2*a-b)/(a+b));	
	}
	return 0;
}
