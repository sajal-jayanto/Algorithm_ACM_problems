#include<stdio.h>
int main()
{
	int member,money,hotel,week,cost,i,j,ok;
	int hotel1[20],week1[20];
	while(scanf("%d %d %d %d",&member,&money,&hotel,&week)!=EOF){
		for(i=0;i<hotel;i++){
			scanf("%d",&hotel1[i]);
			for(j=0;j<week;j++)scanf("%d",&week1[j]);
			ok=0;
			for(j=0;j<week;j++){
				if(week1[j]<member)ok+=1;
				else ok+=0;
			}
			if(ok==0)hotel1[i]=hotel1[i]*member;
			else hotel1[i]=0;
			printf("%d\n",hotel1[i]);
			
		}
		
	}
	return 0;
}
