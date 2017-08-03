#include<stdio.h>
#include<string.h>
int main()
{
	char ar[8],i=0;
	while(scanf("%s",ar)){
		if(ar[0]=='*')break;
		if(strcmp(ar,"Hajj")==0)printf("Case %d: Hajj-e-Akbar\n",++i);
		else printf("Case %d: Hajj-e-Asghar\n",++i);
	}
}
