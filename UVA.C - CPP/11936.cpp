#include<stdio.h>
int main()
{
	int n,a,b,c;
	scanf("%d",&n);
	while((n--)&&(scanf("%d %d %d",&a,&b,&c)==3)){
		if((a+b>c)&&(b+c>a)&&(a+c>b))printf("OK\n");
		else printf("Wrong!!\n");
	}
	return 0;
}
