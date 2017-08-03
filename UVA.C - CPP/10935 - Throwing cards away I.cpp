#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<time.h>
int swop(int);
int ar[100];
int ans[100];
int num;
int main()
{
	//freopen("output.txt","w",stdout);
	int k;
	while(scanf("%d",&num) && num)
	{
		k = 0;
		for(int i=0;i<num;i++)
		{
			ar[i] = i+1;
		}
		for(int i=num;i>=1;i--)
		{
			ans[k++] = ar[0];
			swop(i);
		} 
		printf("Discarded cards:");
		for(int i=0;i<k-1;i++)
		{
			if(i == k-2) 
			{
				printf(" %d",ans[i]);	
			}
			else printf(" %d,",ans[i]);
		} 
		printf("\n");
		if(num == 1) ar[0] = 1;
		printf("Remaining card: %d\n",ar[0]);
	}
	return 0;
}
int swop(int num)
{
	int i,kye;
	kye = ar[1];
	for(i=0;i<num-2;i++)
	{
		ar[i] = ar[i+2];
	}
	ar[i] = kye;
}
