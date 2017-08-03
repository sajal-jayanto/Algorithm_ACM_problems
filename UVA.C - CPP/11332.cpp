#include<stdio.h>
int main()
{
	long long number,sum;
	while((scanf("%lld",&number))==1 && number!=0){
		if(number<10)printf("%lld\n",number);
		else{
			sum=0;
			while(1){
				sum+=number%10;
				number/=10;
				if(number==0){
					number=sum;
					if(number<10)break;
					sum=0;
				}	
			}
			printf("%lld\n",number);	
		}
	}
	return 0;
}
