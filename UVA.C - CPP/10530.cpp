#include<stdio.h>
#include<string.h>
int main()
{
	int ar[20];
	int low,high,low_num,high_num,num,i,j;
	char st[10];
	low=high=low_num=high_num=0;
	while(scanf("%d",&num)  && num!=0)
	{
		ar[i++]=num;
		getchar();
		gets(st);
		if(strcmp(st,"too high")==0)
		{
			high++;	
		}
		else if(strcmp(st,"too low")==0)
		{
			low++;	
		}
		else if(strcmp(st,"right on")==0)
		{
			num=ar[i-1];
			for(j=0;j<i-1;j++)
			{
				if(ar[j]>num)
				{
					high_num++;
				}
				else if(ar[j]<num)
				{
					low_num++;
				} 
			}
			if(high==high_num && low==low_num)
			{
				printf("Stan may be honest\n");
			}
			else printf("Stan is dishonest\n");
			low=high=low_num=high_num=i=0;
		}
	}
	return 0;
}
