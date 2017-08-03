#include<stdio.h>
int main()
{
	int t,e,f,c,count;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&e,&f,&c);
		e=e+f;
		count=0;
		while(1){
			if(c>e)break;
			f=e%c;
			e=e/c;
			count+=e;
			e+=f;
		}
		printf("%d\n",count);
	}
	return 0;
}
