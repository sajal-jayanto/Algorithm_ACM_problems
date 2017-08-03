#include<stdio.h>
int main()
{
	int t,row,col,ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&row,&col);
		row=row-(row%3);
		col=col-(col%3);
		ans=row*col;
		ans=ans/9;
		printf("%d\n",ans);
	}
	return 0;
	
}
