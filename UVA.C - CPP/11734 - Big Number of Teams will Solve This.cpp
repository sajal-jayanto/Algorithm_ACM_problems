#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char my[100];
char juj[100];
int main()
{
	int t,k = 0,ans,ans2;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(my);
		gets(juj);
		ans = ans2 = 0;
 		if(strcmp(my,juj) == 0) printf("Case %d: Yes\n",++k);
		else if(strcmp(my,juj)!= 0)
		{
			for(int i=0;i<strlen(juj);i++)
			{
				if(juj[i]!= 32) ans = ans + juj[i];
			}
			for(int i=0;i<strlen(my);i++)
			{
				if(my[i]!= 32) ans2 = ans2 + my[i];
			}
			if(ans == ans2) 
			{
				for(int i=0;i<(strlen(juj)<strlen(my)?strlen(my):strlen(juj));i++)
				{
					if(my[i]!=juj[i] && (my[i] == 32 || juj[i] == 32))
					{
						printf("Case %d: Output Format Error\n",++k);
						                break;
					}
					if(my[i]!=juj[i] && (my[i]!= 32 && juj[i]!=32))
					{
						printf("Case %d: Wrong Answer\n",++k); 
						                 break;
					}
				}
			}
			else printf("Case %d: Wrong Answer\n",++k);
		}	
	}
	return 0;
}
