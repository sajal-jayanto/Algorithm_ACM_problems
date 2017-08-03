#include<stdio.h>
int main()
{
	int ar[100],i,len=0,count,sum;
	for(i=0;i<100;i++){
		scanf("%d",&ar[i]);
		if(ar[i]==0)break;
			len++;
	}
	printf("PERFECTION OUTPUT\n");
	for(i=0;i<len;i++){
		count=1;
		sum=0;
		while(count!=(ar[i]/2)+1){
			if(ar[i]%count==0)sum+=count;
			count++;
		}
		if(sum==ar[i]) printf("%5d  PERFECT\n",ar[i]);
		if(sum<ar[i])  printf("%5d  DEFICIENT\n",ar[i]);
		if(sum>ar[i])  printf("%5d  ABUNDANT\n",ar[i]);
	}
	printf("END OF OUTPUT\n");
	return 0;
}
