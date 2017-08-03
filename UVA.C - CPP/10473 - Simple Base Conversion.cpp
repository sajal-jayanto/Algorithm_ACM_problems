#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char ar[100];
int main()
{
	long long sum;
	int i;
	while(scanf("%s",ar)!=EOF)
	{
		if(ar[0] == '-')break;
		else if(ar[0] == '0' && ar[1] == 'x')
		{
			sscanf(ar,"%X",&sum);
			printf("%d\n",sum);
		}
		else 
		{
			sscanf(ar,"%d",&sum);
			printf("0x%X\n",sum);
		}	
	}
	return 0;
}
