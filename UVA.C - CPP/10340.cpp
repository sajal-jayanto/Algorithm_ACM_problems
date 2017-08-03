#include <stdio.h>
#include <string.h>
int main()
{
	char s1[1000000], s2[1000000];
	int  cont, i;
	while(scanf("%s %s", s1, s2) != EOF){
		cont=0;
		for(i=0; i < strlen(s2); ++i)
		{
			if(cont < strlen(s1))
			{
				if(s2[i] == s1[cont])
				{
					cont++;
				}
			}
			
		}
			if(cont == strlen(s1))
			{
				printf("Yes\n");
			}
			else printf("No\n");
	}
	return 0;
} 
