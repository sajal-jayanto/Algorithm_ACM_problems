#include<stdio.h>
int main()
{
	int a,b,c;
	while((scanf("%d %d %d",&a,&b,&c)==3)){
		if(a==b && b!=c)printf("C\n");
		if(a==c && a!=b)printf("B\n");
		if(b==c && b!=a)printf("A\n");
		if(a==b && a==c)printf("*\n");
	}
}
