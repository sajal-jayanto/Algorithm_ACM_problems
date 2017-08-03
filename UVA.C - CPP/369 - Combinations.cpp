#include<stdio.h>
#include<math.h>
#include<string.h>
long int combination(long int,long int);
int main()
{
	int N,R;
	while(scanf("%d %d",&N,&R) == 2)
	{
		if(N == 0 && R == 0) break;
		else 
		{
			printf("%d things taken %d at a time is %ld exactly.\n",N,R,combination(N,R));
		}	
	}
	return 0;
}
long int combination(long int N,long int R)
{
	long int ans = 1;
	R = R > N-R ? R :N-R;
	for(int i=1;i<=R;i++)
	{
		ans = ans * (N-R+i);
		ans = ans / i;
	}
	return ans;
}
