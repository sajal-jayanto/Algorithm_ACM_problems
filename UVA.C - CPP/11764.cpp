#include<stdio.h>
int main()
{
	int i,t,n,k=0,high,low,ar[50];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		high=0;
		low=0;
		for(i=0;i<n;i++){
			scanf("%d",&ar[i]);
		}
		for(i=0;i<n-1;i++){
			if(ar[i]<ar[i+1])high++;
			if(ar[i]>ar[i+1])low++;
		}
		printf("Case %d: %d %d\n",++k,high,low);
	}
	
	
	
}
