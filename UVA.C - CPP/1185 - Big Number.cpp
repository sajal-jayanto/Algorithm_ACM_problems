#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void N_digit();
int ar[10000100];
int main()
{
	N_digit();
	int t,num;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&num);
		printf("%d\n",ar[num]);
	}
	return 0;
}
void N_digit()
{
	double ans;
	ar[0] = 1;
	ans = 0.00;
	for(int i=1;i<=10000010;i++)
	{
		ans = ans + log10(i);
		ar[i] = floor(ans)+1;
	}
}
