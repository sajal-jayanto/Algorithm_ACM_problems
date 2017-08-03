#include<stdio.h>
#include<math.h>
#define MAX 1001000
int sum_num(int);
int is_digit();
int ar[MAX] = {0};
int dist[MAX];
int main()
{
	is_digit();
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",(dist[b]-dist[a-1]));
	}
	return 0;
}
int is_digit()
{
	for(int i=2;i<=sqrt(MAX);i++)
	{
		for(int j=i+i;j<=MAX;j=j+i)
		{
			ar[j-1] = 1; 
		}
	}
	int k = 0;
	for(int i=2;i<=MAX;i++)
	{
		if(ar[i-1] == 0 && sum_num(i) == 0) 
		{
			k++;
		}
		dist[i] = k;
	}
	dist[1] = 0;
	return 0;
}
int sum_num(int num)
{
	int n = 0;
	while(num)
	{
		n = n + num % 10;
		num = num /10;
	}
	if(ar[n-1] == 0) return 0;
	else return 1;
}
