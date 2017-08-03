#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int main()
{
	int num1,num2,t;
	char ar[10];
	scanf("%d",&t);
	gets(ar);
	while(t--)
	{
		gets(ar);
		num1 = (ar[0] - 65) * 26 * 26 + (ar[1] - 65)* 26 + (ar[2] - 65) * 1;
		num2 = (ar[4] - 48) * 1000 + (ar[5] - 48) * 100 + (ar[6] - 48) * 10 + (ar[7] - 48);
		num1 = abs(num1 - num2);
		if(num1 <= 100) printf("nice\n");
		else printf("not nice\n");
	}
	return 0;
}
