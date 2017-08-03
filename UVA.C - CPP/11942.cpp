#include<stdio.h>
int main()
{
	int i,t,j,ar[20][10],count,pot=1;
	scanf("%d",&t);
	for(i=0;i<t;i++)
		for(j=0;j<10;j++)scanf("%d",&ar[i][j]);
		printf("Lumberjacks:\n");
	for(i=0;i<t;i++){
		count=0;
		pot=1;
		for(j=0;j<9;j++){
			if(ar[i][j]<ar[i][j+1])count+=0;
			else count+=1;
		}
		if(count==0){
			printf("Ordered\n");
			pot=0;
		}
		else  count=0;
		for(j=0;j<9;j++){
			if(ar[i][j]>ar[i][j+1])count+=0;
			else count+=1;
		}
		if(count==0){
			printf("Ordered\n");
			pot=0;
		}	
		 if(count!=0 && pot==1) printf("Unordered\n");
		 
	}
}
