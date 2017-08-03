#include<stdio.h>
#include<string.h>
int main()
{
	char ar[6];
	int i;
	scanf("%d",&i);
	i=i+1;
	while(i--){
		gets(ar);
		if(((ar[0]=='o')&&(ar[1]=='n'))||((ar[0]=='o')&&(ar[2]=='e'))||((ar[1]=='n')&&(ar[2]=='e')))printf("1\n");
		if(((ar[0]=='t')&&(ar[1]=='w'))||((ar[0]=='t')&&(ar[2]=='o'))||((ar[1]=='w')&&(ar[2]=='o')))printf("2\n");
		if(((ar[0]=='t')&&(ar[1]=='h')&&(ar[2]=='r')&&(ar[3]=='e'))||
		((ar[0]=='t')&&(ar[1]=='h')&&(ar[2]=='r')&&(ar[4]=='e'))||
		((ar[0]=='t')&&(ar[1]=='h')&&(ar[3]=='e')&&(ar[4]=='e'))||
		((ar[0]=='t')&&(ar[2]=='r')&&(ar[3]=='e')&&(ar[4]=='e'))||
		((ar[1]=='h')&&(ar[2]=='r')&&(ar[3]=='e')&&(ar[4]=='e')))printf("3\n");
	}
	return 0;
}
