#include<stdio.h>
#include<string.h>
int main()
{
	char ar[1000100];
	long long i,j,n,l=0,k,yas,big,small;
	while(scanf("%s",ar)!=EOF){
		getchar();
		scanf("%lld",&n);
		printf("Case %lld:\n",++l);
			while(n--){
				yas=0;
				scanf("%lld %lld",&i,&j);
				big=i>j ? i:j;small=i<j ? i:j;
				for(k=small;k<=big;k++){
					if(ar[k]==ar[small])yas+=0;
					else yas+=1;
				}
				if(yas==0)printf("Yes\n");
				else printf("No\n");
			}	
	}
	return 0;
}
