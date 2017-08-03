#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int n,have[12],need[12],count = 0;
	while(scanf("%d",&n) && n >= 0)
	{
		for(int i=0;i<12;i++) scanf("%d",&have[i]);
		for(int i=0;i<12;i++) scanf("%d",&need[i]);
		printf("Case %d:\n",++count);
		for(int i=0;i<12;i++)
		{
			if(n >= need[i])
			{
				printf("No problem! :D\n");
				n = n - need[i];
			}
			else printf("No problem. :(\n");
			n = n + have[i];
		}
	}
	return 0;
}
