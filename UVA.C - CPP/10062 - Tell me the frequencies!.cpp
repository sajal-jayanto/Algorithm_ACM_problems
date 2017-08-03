#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<algorithm>
#define MAX 1010
char ar[MAX];
char str[100];
int  num[100];
using namespace std;
int main()
{
	//freopen("output.txt","w",stdout);
	int count,n = 0;
	char ch;
	while(gets(ar))
	{
		int k = 0;
		int big = 0;
		int small;
		if(n!=0) printf("\n");
		for(int i=32;i<=128;i++)
		{
			count = 0;
			for(int j=0;j<strlen(ar);j++)
			{
				if(i == ar[j]) count++;
			}
			if(count!= 0)
			{
				str[k] = i;
				num[k++] = count;
				if(big < count) big = count;
			}
		}
		small = big;
		for(int i=0;i<k;i++)
		{
			if(small > num[i]) small = num[i]; 
		}
		for(int l=small;l<=big;l++)
		{
			for(int j=128;j>=32;j--) 
			{
				for(int i=0;i<k;i++)
				if(str[i] == j && num[i] == l) 
				printf("%d %d\n",str[i],num[i]);	
			}	
		}
		n++;
	}
	return 0;
}
