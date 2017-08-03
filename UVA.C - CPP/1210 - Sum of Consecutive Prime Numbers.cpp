#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 10010
void find_prime();
void made();
int ar[MAX+1];
int prime[1230];
int count[MAX+1];
int main()
{
	find_prime();
	made();
	int num;
	while(scanf("%d",&num) && num)
	{
		printf("%d\n",count[num]);
	}
	return 0;
}
void made()
{
	int coun,sum;
	for(int i=0;i<=MAX;i++)
	{
		sum = 0;
		for(int j=i;j<1230;j++)
		{
			sum = sum + prime[j];
			if(sum > MAX) break;
			count[sum]++;
		}
	}	
}
void find_prime()
{
	int k = 0;
	prime[k++] = 2;
	for(int i=3 ;i<=sqrt(MAX) ;i = i + 2)
	{
		if(ar[i] == 0)
		for(int j = i * i ;j<=MAX; j = j + (2 * i))   
		ar[j] = 1;		
	}
	for(int i=3 ;i<=MAX; i = i + 2)
	{
		if(ar[i] == 0) prime[k++] = i;
	}
	k = 0;
	for(int i=2;i<=MAX;i++) 
	{
		if(i == prime[k]) ar[i] = 0, k++;
		else ar[i] = 1;
	}

}

