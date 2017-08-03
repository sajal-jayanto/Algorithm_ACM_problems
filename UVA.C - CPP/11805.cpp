#include<stdio.h>
int main()
{
	int t,n,k,p,i,l=0;
	scanf("%d",&t);
	while(t-- && (scanf("%d %d %d",&n,&k,&p)==3)){
		for(i=0;i<p;i++){
			if(k==n)k=1;
			else k++;
		}
		printf("Case %d: %d\n",++l,k);
	}
	return 0;
}
