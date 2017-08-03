#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main()
{
	int a,b,c,count = 0;
	char ch1,ch2;
	char ar[5];
	while(scanf("%d%c%d%c%s",&a,&ch1,&b,&ch2,ar) == 5)
	{
		if(ar[0]!='?')
		{
			c = 0;
			for(int i=0;i<strlen(ar);i++)
			{
				c = ((c * 10) + ar[i] - 48);
			}
			if(ch1 == '+' && a+b == c) count++;
			else if(ch1 == '-' && a-b == c)  count++;
		} 
	}
	printf("%d\n",count);
	return 0;
}
