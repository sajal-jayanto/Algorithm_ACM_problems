#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,k;
	char ar[500];
	char rev[500];
	while(gets(ar))
	{
		k=0;
		for(i=0;i<strlen(ar);i++)
		{
			if((ar[i]==32))
			{
				j=i-1;
				while(1)
				{
					if((ar[j]==32)||(j==-1))
					{
						break;
					}
					rev[k++]=ar[j--];
				}
				rev[k++]=32;
			}
			
		}
		for(i=strlen(ar)-1;ar[i]!=32;i--)
		{
			if(i==-1)
			{
				break;
			}
			rev[k++]=ar[i];
		}
		rev[k]='\0';
		printf("%s\n",rev);
	}
	return 0;
}
