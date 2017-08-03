#include<stdio.h>
#include<math.h>
int main()
{
	long long a,b,i,squr,powar,count;
	while((scanf("%lld %lld",&a,&b)==2) && (a!=0 && b!=0)){
		count=0;
		for(i=a;i<=b;i++){
			squr=sqrt(i);
			powar=pow(squr,2);
			if(i==powar)count++;
		}		
		printf("%lld\n",count);
	}
}
