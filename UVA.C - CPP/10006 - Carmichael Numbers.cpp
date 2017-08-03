#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX 65000
void IS_PRIME();
long long BIG_MOD(int,int,int);
void made();
int ar[MAX];
int crimenal[MAX+1];
int main()
{
	IS_PRIME();
	made();
	int num;
	while(scanf("%d",&num) && num)
	{
		if(crimenal[num] == 1) printf("The number %d is a Carmichael number.\n",num);
		else printf("%d is normal.\n",num);
	}
	return 0;
}
void made()
{
	int k;
	for(int i=2;i<=MAX;i++)
	{
		if(ar[i-1]!=0)
		{
			k = 0;
			for(int j=2;j<i;j++)
			{
				if(BIG_MOD(j,i,i)!= j) 
				{
					k = 1;
					break;	
				}
				else k = 0;
			}
			if(k == 0)  crimenal[i] = 1;
			else crimenal[i] = 0;
		} 
		else crimenal[i] = 0;
	}
}
void IS_PRIME()
{
	for(int i=2;i<=sqrt(MAX);i++)
	{
		for(int j=i+i;j<=MAX;j=j+i)
		{
			ar[j-1] = 1;
		}
	}
}
long long BIG_MOD(int N,int P,int M)
{
	long long sum;
	if (P == 0) return 1;
	if(P%2 == 0)
	{
		sum = BIG_MOD(N,P/2,M);
		return ((sum%M)*(sum%M))%M;
	}
	else return ((N%M)*(BIG_MOD(N,P-1,M)%M))%M;
}
