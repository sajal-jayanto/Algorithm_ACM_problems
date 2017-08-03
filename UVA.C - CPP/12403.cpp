#include<stdio.h>
#include<string.h>
int main()
{
	char ar[10];
	int t,ta,money=0;
	scanf("%d",&t);
	getchar();
	while(t--){
		scanf("%s",ar);
		if(strcmp(ar,"donate")==0){
			scanf("%d",&ta);
			money+=ta;
		}
		else if (strcmp(ar,"report")==0)
		printf("%d\n",money);
	} 
	return 0;
}
