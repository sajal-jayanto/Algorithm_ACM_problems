#include<stdio.h>
int main()
{
	int i,j,t,n,ar[10000];
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d",&ar[j]);
			if(ar[0]<ar[j])
			ar[0]=ar[j];
		}
		printf("Case %d: %d\n",i,ar[0]);
	}
	return 0;
	
}
