#include<stdio.h>
long long ar[1000100];
int main()
{
	long long i,j,k,sum,s,b;
	for(k=0;k<1000100;k++){ 
		sum=1;
		s=k+1; 
		while(s!=1){ 
			sum++; 
			if(s%2==0)s=s/2; 
			else s=(3*s)+1; 
		}
		ar[k]=sum;
	}
	while(scanf("%lld %lld",&i,&j)==2){
		sum=0;
		s=i<j?i:j; 
		b=i>j?i:j;
		for(k=s-1;k<b;k++){
			if(sum<ar[k])
			sum=ar[k];
		}
		printf("%lld %lld %lld\n",i,j,sum);
	} 
	return 0;
}
