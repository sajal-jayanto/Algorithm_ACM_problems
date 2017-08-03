#include<stdio.h>
#include<math.h>
#include<string.h>
long int NCR(long int,long int);
int main()
{
	long int N,R;
	while(scanf("%ld %ld",&N,&R) == 2)
	{
		if(N == 0 && R == 0) break;
		else printf("%ld\n",NCR(N,R));	
	}
	return 0;
}
long int NCR(long int N,long int R)
{
	long int ans = 1;
	R = R < N-R ? R : N-R;
	for(int i=1;i<=R;i++)
	{
		ans = ans * (N-R+i);
		ans = ans / i;
	}
	return ans;
}
