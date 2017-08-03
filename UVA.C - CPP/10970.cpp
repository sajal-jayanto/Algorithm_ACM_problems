#include<stdio.h>
int main()
{
	int row,col,piece,i;
	while(scanf("%d %d",&row,&col)!=EOF){
		piece=0;
		piece=row-1;
		for(i=0;i<row;i++){
			piece+=col-1;
		}
		printf("%d\n",piece);
	}
	
	
	
}
