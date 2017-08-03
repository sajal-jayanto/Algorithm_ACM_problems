#include<stdio.h>
int main()
{
	int v,t,sum;
	while((scanf("%d %d",&v,&t)==2)){
		sum=v*t;
		sum=sum*2;
		printf("%d\n",sum);
	}
	return 0;
}
