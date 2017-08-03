#include<stdio.h>
int main()
{
	int t,n,i,j,ar[11],small,big,k=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d",&ar[i]);
		for(j=0;j<n;j++){
			big=0;
			small=0;
			for(i=0;i<n;i++){
				if(ar[j]>ar[i])big++;
				if(ar[j]<ar[i])small++;
			}
			if(small==big){
				printf("Case %d: %d\n",++k,ar[j]);
							break;
			}
		}	
	}
	return 0;
}
