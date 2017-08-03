#include<stdio.h>
int main()
{
	int x1,y1,x2,y2,i,count;
	while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2) && (x1!=0 && y1!=0 && x2!=0 && y2!=0 ))
	{
		if(x1==x2 && y1==y2)
		{
			printf("0\n");
		}
		else if(x1==x2 || y1==y2)
		{
			printf("1\n");
		}
		else
		{
			if(x2>x1)
			{
				count = x2-x1 ;
				if(count+y1==y2||y1-count==y2)
				{
					printf("1\n");
					count=0;
				}
			
			}
			else 
			{
				count=x1-x2;
				if(count+y1==y2||y1-count==y2)
				{
					printf("1\n");
					count=0;
				}
			}
			if(count!=0)
			{
				printf("2\n");
			}
		}
	}
	return 0;
}
