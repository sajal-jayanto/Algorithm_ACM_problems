#include <stdio.h>
int main()
{
	int number;
	while(scanf("%d",&number) && number!=0)
	{
		
		if( number<=101 )
		{
			printf("f91(%d) = %d\n",number,91);
		}
		else printf("f91(%d) = %d\n",number,number-10);
	}
	return 0;
}
