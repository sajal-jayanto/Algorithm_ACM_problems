#include<stdio.h>
int main()
{
	long long number,sum;
	int ar[35],i,j;
	while(scanf("%lld",&number) && number!=0){
		i=0;
		sum=0;
		while(number){
			ar[i++]=number%2;
			number/=2;
		}
		printf("The parity of ");
		for(j=i-1;j>=0;j--){
			sum+=ar[j];
			printf("%d",ar[j]);
		}
		printf(" is %d (mod 2).\n",sum);
	}
	return 0;
}

