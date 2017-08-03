#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char frist[15];
char second[15];
int nu_frist[15];
int nu_second[15];
int main()
{
	int k,sum,carry;
	while(scanf("%s %s",frist,second) == 2)
	{
		if(strlen(frist) == 1 && strlen(second) == 1  && frist[0] == 48 && second[0] == 48) break;
		for(int i=0;i<15;i++) 
		{
			nu_second[i] = 0;
			nu_frist[i] = 0;
		}
		k = 15;
		for(int i=strlen(frist)-1;i>=0;i--)
		{
			nu_frist[--k] = frist[i]-48;
		}
		k = 15;
		for(int i=strlen(second)-1;i>=0;i--)
		{
			nu_second[--k] = second[i]-48;
		}
		sum = 0;
		carry = 0;
		for(int i=14;i>=0;i--)
		{
			sum = sum + nu_frist[i] + nu_second[i];
			if(sum >= 10)
			{
				carry++;
				sum = sum/10;
			}
			else sum = 0;
		}
		if(carry == 0) printf("No carry operation.\n");
		else if(carry == 1) printf("1 carry operation.\n");
		else printf("%d carry operations.\n",carry);
	}
	return 0;
}
