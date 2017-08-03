#include<stdio.h>
#include<string.h>
int main()
{
	char ar[10][25];
	int i,t,j=0,big,number[10];
	scanf("%d",&t);
	getchar();
	while(t--){
	for(i=0;i<10;i++)scanf("%s %d",ar[i],&number[i]);	
		big=number[0];
		for(i=0;i<10;i++)if(big<number[i])big=number[i];
			printf("Case #%d:\n",++j);
				for(i=0;i<10;i++)if(big==number[i])printf("%s\n",ar[i]);
	}
	
}
