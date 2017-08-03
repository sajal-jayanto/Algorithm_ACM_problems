#include<stdio.h>
int main()
{
	int a,b,n,i,j,k,m;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		for(m=1;m<=b;m++){
			for(j=1;j<=a;j++){
				for(k=1;k<=j;k++)printf("%d",j);
					printf("\n");
			}
			for(j=a-1;j>=1;j--){
				for(k=j;k>=1;k--)printf("%d",j);
					if(i==n-1 && m==b && j==1);
					else printf("\n");
			}
			if(m!=b)printf("\n");
		}
		printf("\n");
	}
}
