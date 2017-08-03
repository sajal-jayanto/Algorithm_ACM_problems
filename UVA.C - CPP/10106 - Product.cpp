#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAX 510
char a[MAX];
char b[MAX];
int made[MAX][MAX+1];
int ans[MAX+1];
int main()
{
	//freopen("output.txt","w",stdout);
	int n,len;
	int sum,k,p;
	while(scanf("%s %s",a,b) == 2)
	{
		n = len = 0;
		for(int i=strlen(b)-1;i>=0;i--)
		{
			sum = k = 0; p = n;
			while(p--) made[n][k++] = 0;
			for(int j=strlen(a)-1;j>=0;j--)
			{
				sum = sum + ((a[j] - 48) * (b[i] - 48));
				made[n][k++] =  sum % 10;
				sum = sum / 10;	 
			}
			if(sum!=0)   made[n][k++] = sum;	
			if(len < k) len = k;	
			n++; 
		}
		sum = 0;
		k = 0;
		for(int j=0;j<len;j++)
		{
			for(int i=0;i<n;i++)
			{
				sum = sum + made[i][j];
				made[i][j] = 0;
			}
			ans[k++] = sum % 10;
			sum = sum / 10; 
		}
		if(sum!=0) ans[k++] = sum;
		sum = 0;
		for(int i=k-1;i>=0;i--) 
		{
			sum = sum + ans[i];
			if(0 < sum) break;
			else k--;
		}	
		if(sum!=0)
		{
			for(int i=k-1;i>=0;i--)   printf("%d",ans[i]);
		}
		else printf("0");
		printf("\n");
	}
	return 0;
}
