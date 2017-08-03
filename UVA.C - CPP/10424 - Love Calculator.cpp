#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<math.h>
int one_digit(int);
int main()
{
	char frist[30];
	char second[30];
	int sum1,sum2;
	while(gets(frist))
	{
		gets(second);
		sum1 = 0; sum2 = 0;
		for(int i=0;i<strlen(frist);i++)
		{
			if(islower(frist[i])!=0) sum1 = sum1 + (frist[i] - 96);
			if(isupper(frist[i])!=0) sum1 = sum1 + (frist[i] - 64);
		}
		for(int i=0;i<strlen(second);i++)
		{
			if(islower(second[i])!=0) sum2 = sum2 + (second[i] - 96);
			if(isupper(second[i])!=0) sum2 = sum2 + (second[i] - 64);
		}
		sum1 = one_digit(sum1);
		sum2 = one_digit(sum2);
		if(sum1 > sum2) printf("%.2lf %%\n",sum2/(sum1 *1.00) * 100);
		else printf("%.2lf %%\n",sum1/(sum2 *1.00) * 100);
	}
	return 0;
}
int one_digit(int number)
{
	int n = 0;
	while(number)
	{
		n = n + number%10;
		number = number/10;
	}
	if(n >= 10) one_digit(n);
	else return n;
}
