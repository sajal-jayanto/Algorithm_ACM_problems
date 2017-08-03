#include<stdio.h>
int main()
{
	int n,i,k=0,count=1;
	for(i=0;i<2100;i++){
		scanf("%d",&n);
		if(n<0)
		break;
		if((0<n)&&(n<10001)){
			while(1){
				
				count+=count;
					k++;
				if(count>=n)
					break;
			}
			if(n==1)k=0;
				printf("Case %d: %d\n",i+1,k);
				count=1;
				k=0;	
		}
	}
	return 0;
}
