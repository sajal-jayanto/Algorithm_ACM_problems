#include<stdio.h>
int main()
{
	int i=0,t,x,y,z,big,small;
	scanf("%d",&t);
	while((i<t)&&(t<20)&&(scanf("%d %d %d",&x,&y,&z)==3)){	
		if((1000<=x&&x<=10000)&&(1000<=y&&y<=10000)&&(1000<=z&&z<=10000)){		
			big=((x>y)?(x>z?x:z):(y>z?y:z));
			small=((x<y)?(x<z?x:z):(y<z?y:z));
			if(big>x&&x>small)printf("Case %d: %d\n",i+1,x);
			if(big>y&&y>small)printf("Case %d: %d\n",i+1,y);
			if(big>z&&z>small)printf("Case %d: %d\n",i+1,z);
		}
		i++;
	}
	return 0;
}
