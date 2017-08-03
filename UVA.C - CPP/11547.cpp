#include<stdio.h>
int main()
{
	long long t,n,i,sum;
	scanf("%lld",&t);
	while(t-- && (scanf("%lld",&n)==1)){
		n=n*567;
		n=n/9;
		n=n+7492;
		n=n*235;
		n=n/47;
		n=n-498;
		for(i=0;i<2;i++){
			sum=n%10;
			n=n/10;
		}
		if(sum<0)sum=sum*-1;
		printf("%lld\n",sum);
	}
	return 0;	
}
