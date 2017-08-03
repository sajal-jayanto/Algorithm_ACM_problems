#include <stdio.h>
int main()
{
	//freopen ("output.txt","w",stdout);
	int t,H,M;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%c%d",&H,&ch,&M);
		if(M==0)
		{
			 H = 12 - H;
		}
		else 
		{
			M = 60 - M;
			if(H == 12)
			{
				H = 11;
			}
			else 
			{
				H = 12 - H;
				H = H -1;
			}
		}
		if(H<=0)
		{
			H = 12;
		}
		 printf("%02d%c%02d\n",H,ch,M);
	}
	return 0;
}
