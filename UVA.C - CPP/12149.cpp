#include<stdio.h>
#include<math.h>
int main()
{
	long long number,i,sum;
	while(scanf("%lld",&number)&& number!=0){
		sum=0;
		for(i=1;i<=number;i++)sum+=pow(i,2);
		printf("%lld\n",sum);
	}
	return 0;
}
