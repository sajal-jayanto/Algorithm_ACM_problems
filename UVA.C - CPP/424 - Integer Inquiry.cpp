#include<stdio.h>
#include<string.h>
char ar[110][110];
int  nu[110][110]={0};
int ans[10000];
int main()
{
	int i,len=0;
	for(i=0;;i++)
	{
		scanf("%s",ar[i]);
		if(strlen(ar[i])==1 && ar[i][0]=='0') break;
		if(strlen(ar[i])>len) len = strlen(ar[i]);
	}
	for(int j=0;j<i;j++)
	{
		int len2 = len-1;
		for(int m=strlen(ar[j])-1;m>=0;m--)
		{
			nu[j][len2--] = (ar[j][m]-48);
		}
	}
	int l = 0;
	int sum = 0;
	for(int j=len-1;j>=0;j--)
	{
		for(int k=0;k<i;k++)
		{
			sum = sum + nu[k][j];
		}
		ans[l++] = sum%10;
		sum = sum /10;	
	}
	if(sum!=0) ans[l++] = sum;
	for(i=l-1;i>=0;i--)
	{
		printf("%d",ans[i]);
	}
	printf("\n");
	return 0;
}
