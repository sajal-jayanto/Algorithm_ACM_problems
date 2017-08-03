#include<stdio.h>
#include<string.h>
int main()
{
	int t,ar[20],i,sum,sum2;
	char str[20];
	scanf("%d",&t);
	getchar();
	while(t--){
		gets(str);
		sum=0;
		sum2=0;
		for(i=0;i<19;i++){
			ar[i]=str[i]-48;
			if(i==0||i==2||i==5||i==7||i==10||i==12||i==15||i==17){
				ar[i]=(ar[i]*2);
				while(ar[i]){
						sum+=ar[i]%10;
						ar[i]/=10;
				}
			}
			else if(i==1||i==3||i==6||i==8||i==11||i==13||i==16||i==18){
					while(ar[i]){
						sum2+=ar[i]%10;
						ar[i]/=10;
					}	
			}
		}
		if((sum+sum2)%10==0)printf("Valid\n");
		else printf("Invalid\n");
	}
	return 0;
}
