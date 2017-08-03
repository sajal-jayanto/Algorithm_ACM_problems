#include<stdio.h>
#include<string.h>
int main()
{
	int t,i,j,k,l,m=0,count;
	char ar[2001];
	scanf("%d",&t);
	while(t-- && scanf("%s",ar)){
		l=0;
		printf("Case %d: ",++m);
		for(i=48;i<123;i++){
			count=0;
			for(j=0;j<strlen(ar);j++){
				if(i==ar[j])
				   count++;
			}	
			if(count!=0){
				k=0;
				for(j=2;j<=count/2;j++){
					if(count%j==0)
						k++;
				}		
				if(k==0 && count!=1){
					printf("%c",i);
						l++;
				}
			}
		}
		if(l==0)printf("empty\n");
		else printf("\n");
	}
	return 0;
}
