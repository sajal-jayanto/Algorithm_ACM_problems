#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
int main()
{
	long long number,i,count;
	while(scanf("%lld",&number) == 1)
	{
		count = 1;
		for(i=0;count < number;i++)
		{
			if(i%2 == 0) count = count * 9;
			else count = count * 2;
		}
		if(i%2 == 0) printf("Ollie wins.\n");
		else printf("Stan wins.\n");	
	}
	return 0;
}
