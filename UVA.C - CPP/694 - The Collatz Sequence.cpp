#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	long long  A,L,S,count,k = 0;
	while(scanf("%lld %lld",&A,&L) == 2)
	{
		if(A < 0 && L < 0) break;
		count = 0;
		S = A;
		while(A <= L)
		{
			if(A == 1)
			{
				count++;
				break; 	
			} 
			else if(A % 2 == 0) A = A / 2, count++;
			else if(A % 2 == 1) A = (A * 3) + 1,count++;
		}
		printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",++k,S,L,count);	
	}
	return 0;
}
