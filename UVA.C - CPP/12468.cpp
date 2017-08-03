#include<stdio.h>
int main()
{ 
	int i,j,k,up,down;
	while(scanf("%d %d",&i,&j) && (i!=-1 && j!=-1)){
		up=down=0;
		k=i;
		while(i!=j){
			if(i==99){
				i=0;
				up++;
			}
			else{
				up++;
				i++;
			}
		}
		while(k!=j){
			if(k==0){
				k=99;
				down++;
			}	
			else {
				down++;
				k--;
			}
		}
		if(up>down)printf("%d\n",down);
		else printf("%d\n",up);
	}
	return 0;
}
