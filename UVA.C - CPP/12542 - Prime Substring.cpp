#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 100100
void is_prime();
int ar[MAX]={0};
char str[260];
int main()
{
	int sum,ans;
	is_prime();
	while(scanf("%s",str)!=EOF)
	{
		if(strlen(str) == 1 && str[0] == '0') break;
		ans = 0;
	 	for(int i=0;i<strlen(str);i++)
	 	{
	 		sum = 0;
	 		for(int j=i;j<strlen(str);j++)
	 		{
	 			sum = (sum * 10) + (str[j] - 48);
				if(sum > 100000) break;
				else 
				{
					if(ar[sum-1] == 0 && ans < sum)
					{
						ans = sum;
					}
				} 
	 		}
	 	}
	 	printf("%d\n",ans);
	}
	 return 0;
}
void is_prime()
{
	for(int i=2; i<=sqrt(MAX); i++)
	{
		for(int j=i+i; j<=MAX; j=j+i)
		{
			ar[j-1] = 1;
		}
	}
	ar[0] = 1;
}
