#include<stdio.h>
int main()
{
	int t,i=0,h,w,l;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&h,&w,&l);
		if(h<=20 && w<=20 && l<=20)printf("Case %d: good\n",++i);
		else printf("Case %d: bad\n",++i);
	}
	return 0;
}
