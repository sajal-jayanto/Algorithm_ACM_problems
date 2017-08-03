#include <stdio.h>
#include<string.h>
int main()
{
	char ar[600];
	int t,i,count,M,A,R,G,I,T;
	scanf("%d",&t);
	getchar();
	while(t--)
	{	
		gets(ar);
		M=A=R=G=I=T=0;
		for(i=0;i<strlen(ar);i++)
		{
			if(ar[i]==77)
			{
				M++;
			}
			else if(ar[i]==65)
			{
				A++;
			}
			else if(ar[i]==82)
			{
				R++;
			}
			else if(ar[i]==71)
			{
				G++;
			}
			else if(ar[i]==73)
			{
				I++;
			}
			else if(ar[i]==84)
			{
				T++;
			}
		}
		count=0;
		while(1)
		{
			if(M>=1 && A>=3 && R>=2 && G>=1 && I>=1 && T>=1)
			{
				count++;
				M = M-1;
				A = A-3;
				R = R-2;
				G = G-1;
				I = I-1;
				T = T-1;
			}
			else break;
		}
		printf("%d\n",count);	
	}
	return 0;
}
