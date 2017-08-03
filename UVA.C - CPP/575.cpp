#include <stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	char ar[35];
	int number[35],count=0,ans=0,i,j;
	while(1){
		scanf("%s",ar);
		if(ar[0]=='0')break;
		for(i=0;ar[i]!=NULL;i++){
			number[i]=(ar[i]-48);
			count++;	
		}
			j=count;
		for(i=0;i<count;i++){
			ans+=number[i]*(pow(2,j)-1);
			j--;
		}
		printf("%d\n",ans);
		count=0;
		ans=0;	
	}
	return 0;
}
