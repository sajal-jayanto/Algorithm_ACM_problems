#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	//freopen ("output.txt","w",stdout);
	char frist[300];
	char second[300];
	int i,j,k;
	while(gets(frist))
	{
		if(strcmp(frist,"DONE")==0)
		{
			break;
		}
		else 
		{
			j=0;
			for(i=0;i<strlen(frist);i++)
			{
				if(isalpha(frist[i])!=0)
				{
					second[j++] = frist[i];	
				}
			}
			second[j]='\0';
			i=-1;
			j=0;
			while(second[++i]!='\0');
			while(i)
			{
				frist[j++]=second[--i];
			}
			frist[j]='\0';
		}
		k=0;
		for(i=0,j=0;i<strlen(frist),j<strlen(second);i++,j++)
		{
			if(frist[i]==second[j])
			{
				k=k+0;	
			}
			else if(frist[i]==(second[j]-32))
			{
				k=k+0;
			}
			else if((frist[i]-32)==second[j])
			{
				k=k+0;
			}
			else 
			{
				k=k+1;
				break;
			}
		}
		if(k==0)
		{
			printf("You won't be eaten!\n");
		}
		else printf("Uh oh..\n");
	}
	return 0;
}
