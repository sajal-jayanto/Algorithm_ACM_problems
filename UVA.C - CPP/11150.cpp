#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,n,k,sum;
	while(scanf("%d",&i)!=EOF){
		sum=i;
		i++;
		while(1){
			if(3>i)break;
			k=i%3;
			i=i/3;
			sum=sum+i;
			i=i+k;
		}
		printf("%d\n",sum);
	}
	return 0;
}
