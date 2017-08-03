#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int t,len,i;
	char ar[1000];
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		scanf("%s",ar);
		len = strlen(ar);
		if(len==1 && (ar[0]==49 ||ar[0]==52)) printf("+\n");
		else if(len==2 && (ar[0]==55 && ar[1]==56)) printf("+\n");
		else if(ar[len-1]==53 && ar[len-2]==51) printf("-\n");
		else if(ar[0]==57 && ar[len-1]==52) printf("*\n");
		else if(ar[0]==49 && ar[1]==57 && ar[2]==48) printf("?\n");
		
	}
	return 0;
}
