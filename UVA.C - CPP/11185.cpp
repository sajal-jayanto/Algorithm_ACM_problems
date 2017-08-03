#include<stdio.h>
int main()
{
	int a[100],num,i,len;
	while(scanf("%d",&num) && num>-1)
	{	if(num==0)
		printf("%d",0);
	  	i=0;len=0;
		while(num)
		{
        	a[i]=num%3;
        	num=num/3;
        	i++;
        	len++;
    	}
        for(i=len-1;i>=0;i--)
        printf("%d",a[i]);
        printf("\n");
    }
	return 0;
}
