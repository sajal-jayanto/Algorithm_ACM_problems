#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
char ar[1000000];
int main()
{
	long long D4,D100,D400,D15,D55,digit,count = 0;
	while(scanf("%s",ar)!=EOF)
	{
		D4 = D100 = D400 = D15 = D55 = 0;
		if(count!=0) printf("\n");
		for(int i=0;i<strlen(ar);i++)
		{
			digit = ar[i] - 48;
			D4 = D4 + digit;
			D100 = D100 + digit;
			D400 = D400 + digit;
			D15 = D15 + digit;
			D55 = D55 + digit;
			D4 = D4 % 4;
			D100 = D100 % 100;
			D400 = D400 % 400;
			D15 = D15 % 15;
			D55 = D55 % 55;
			D4 = D4 * 10;
			D100 = D100 * 10;
			D400 = D400 * 10;
			D15 = D15 * 10;
			D55 = D55 * 10;
		}
		if((D4 == 0 && D100!=0) || D400 == 0)
		{
			printf("This is leap year.\n");
			if(D15 == 0) printf("This is huluculu festival year.\n");
			if(D55 == 0) printf("This is bulukulu festival year.\n");
		}
		else 
		{
			if(D15 == 0) printf("This is huluculu festival year.\n");
			else printf("This is an ordinary year.\n");
		}
		count++;
	}
	return 0;
}
