#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
void go_to();
int ar[60000][3]={0};
int main()
{
	go_to();
	int t,number;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&number);
		if(ar[number][0] == 0 && ar[number][1] == 0 && ar[number][2] == 0 && number!=0) printf("-1\n");
		else printf("%d %d %d\n",ar[number][0],ar[number][1],ar[number][2]);	
	}
	return 0;
}
void go_to()
{
	int ans;
	for(int i=0;i<=224;i++)
	{
		for(int j=0;j<=224;j++)
		{
			for(int l=0;l<=224;l++)
			{
				if(i<=j && j<=l)
				{
					ans = (i*i) + (j*j) + (l*l);
					if( ans <=50176 && (ar[ans][0] == 0 && ar[ans][1] == 0 && ar[ans][2] == 0))
					{
						ar[ans][0] = i;
						ar[ans][1] = j;
						ar[ans][2] = l;	
					}
				}	
			}
		}
	}
}
