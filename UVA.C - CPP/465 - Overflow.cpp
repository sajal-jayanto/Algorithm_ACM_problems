#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#define MAX 2147483647
char frist[10000];
char second[10000];
int main()
{
	//freopen("output.txt","w",stdout);
	char ch;
	long double num1,num2;
	while(scanf("%s %c %s",frist,&ch,second) == 3)
	{
		printf("%s %c %s\n",frist,ch,second);
		num1 = atof(frist);
		num2 = atof(second);
		if(num1 > MAX) printf("first number too big\n");
		if(num2 > MAX) printf("second number too big\n");
		if(ch == '+')
		{
			if((num1+num2) > MAX) printf("result too big\n");
		}
		if(ch == '*')
		{
			if((num1 * num2) > MAX) printf("result too big\n");
		}
	}
	return 0;
}
