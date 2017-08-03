#include<stdio.h>
#include<string.h>
int main()
{
    int j,i,t,len;
    char ar[100];
    while(scanf("%d",&t) && t!=0){
    	scanf("%s",ar);
    	len=(strlen(ar)/t);
    	for(i=0;i<t;i++){
    		for(j=len*(i+1)-1;j>=len*i;j--)
    		printf("%c",ar[j]);
    	}
		printf("\n");
    }   
       return 0;
}
