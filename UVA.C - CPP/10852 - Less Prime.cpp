#include<stdio.h>
#include<math.h>
#define MAX 10100
int ar[MAX] = {0};
int is_prime();
int main()
{
	is_prime();
	int t,num;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&num);
		num = (num/2)+1;
		while(ar[num-1]!=0)
		{
			 num++;
		}
		printf("%d\n",num);
	}
	return 0;
}
int is_prime()
{
	for(int i=2;i<=sqrt(MAX);i++)
	{
		for(int j=i+i;j<=MAX;j=j+i)
		{
			ar[j-1] = 1; 
		}
	}
	return 0;
}
