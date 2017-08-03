#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define MAX 1000100
int frist[MAX];
int second[MAX];
int ans[MAX];
int main()
{
	//freopen("output.txt","w",stdout);
	int t,n,sum,count = 0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum = 0;
		int k = 0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&frist[i],&second[i]);
		}
		if(count!=0) printf("\n");
		for(int i=n-1;i>=0;i--)
		{
			sum = sum + frist[i] + second[i];
			ans[k++] = sum % 10;
			if(sum > 9) sum = 1;
			else sum = 0;
		}
		if(sum == 1)  ans[k++] = sum;
		for(int i=k-1;i>=0;i--) printf("%d",ans[i]);
		printf("\n");
		count++;
	}
	return 0;
}
