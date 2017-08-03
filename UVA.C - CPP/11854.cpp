#include<stdio.h>
#include<math.h>
int main()
{
	long long a,b,c,big;
	while((scanf("%lld %lld %lld",&a,&b,&c)==3) && (a!=0 && b!=0 && c!=0)){
		big=(a>b&&a>c?a:b>c?b:c);
		a=pow(a,2);
		b=pow(b,2);
		c=pow(c,2);
		big=pow(big,2);
		if((a!=big && b!=big) &&(a+b==c))printf("right\n");
		else if((a!=big && c!=big) &&(a+c==b))printf("right\n");
		else if((b!=big && c!=big) &&(b+c==a))printf("right\n");
		else printf("wrong\n");
	}
	return 0;
}
