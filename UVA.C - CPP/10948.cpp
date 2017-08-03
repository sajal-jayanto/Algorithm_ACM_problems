#include<stdio.h>
int is_prim(int);
void prim_number();
int ar[1000000]={0};
int prim[78500];
int main()
{
	//freopen ("out.txt","w",stdout);
	int number,i,j,n,count;
	prim_number();
	while(scanf("%d",&number) && number!=0 )
	{
		for(i=0;;i++)
		{
			if(prim[i]>=number)
			{
				printf("%d:\nNO WAY!\n",number);
				      break;
			}
			n=number-prim[i];
			if(ar[n-1]==0)
			{
				printf("%d:\n%d+%d\n",number,prim[i],n);
								break;
			}
		}
	}
	return 0;
}
void prim_number()
{
	int i,j,k;
	ar[0]=1;
	for(i=2;i<=1000;i++)
	{
		if(is_prim(i)==0)
		{
			for(j=i;j<=1000000;j=j+i)
			{
				if(j==i)
				ar[j-1]=0;
				else ar[j-1]=1;
			}
		}
	}
	k=0;
	for(i=2;i<=1000000;i++)
	{
		if(ar[i-1]==0)
		{
			prim[k++]=i;
		}
	}
}
int is_prim(int num)
{
	int i,count=0;
	if(num%2==0 && num !=2)
	{
		return 1;
	}
	for(i=2;i<=num/2;i++)
	{
		if(num%i==0)
		{
			count=1;
			return 1;
			break;
		}
	}
	if(count == 0)
	{
		return 0;
	}
}
