#include <stdio.h>
int main()
{
	int i,t,number,revers,num,ar[10];
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<10;i++)
		{
			ar[i] = 0;	
		}
		scanf("%d",&number);
		if(number==0)
		{
			ar[0]+=1;	
		}
		for(i=1;i<=number;i++)
		{
			if(i<=9)
			{
				ar[i]+=1;
			}
			else 
			{
				num=i;
				while(num)
				{
					revers=num%10;
					ar[revers]+=1;
					num=num/10;
				}
			}
		}
		for(i=0;i<10;i++)
		{	
			if(i!=9)
			printf("%d ",ar[i]);
			else printf("%d",ar[i]);
		}
		printf("\n");
	}
	return 0;
}
