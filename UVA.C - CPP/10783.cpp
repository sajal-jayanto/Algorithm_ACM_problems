#include<stdio.h>
int main()
{
	int t,a,b,ans,i,j=0;
	scanf("%d",&t);
	while(t-- &&(scanf("%d %d",&a,&b)==2)){
		ans=0;
		for(i=a;i<=b;i++){
			if(i%2!=0)ans+=i;
		}
		printf("Case %d: %d\n",++j,ans);
	}
	
}
