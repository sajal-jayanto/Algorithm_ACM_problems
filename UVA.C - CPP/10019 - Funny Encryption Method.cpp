#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	char ar[5];
	int t,D,H,a,b,k;
	scanf("%d",&t);
	gets(ar);
	while(t--)
	{
		gets(ar);
		sscanf(ar,"%d",&D);
		sscanf(ar,"%X",&H);
		a = b = 0;
		for(int i = 31 ; i >= 0 ; i --)
		{
			k = D >> i;
			if(k & 1) a++;
			k = H >> i;
			if(k & 1) b++;
		}
		printf("%d %d\n",a,b);		
	}
	return 0;
}
