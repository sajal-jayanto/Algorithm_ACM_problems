#include<stdio.h>
int main()
{
	int t,i=0;
    int a,b,ans;
    scanf("%d",&t);
	while(i<t&&(scanf("%d %d",&a,&b)==2))
	{
		if(a>b)printf(">\n");
		if(a<b)printf("<\n");
		if(a==b)printf("=");
		i++;
	}
	return 0;
}
