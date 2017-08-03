#include<stdio.h> 
int main() 
{ 
	int T,N,i,j,A,B,mile,juice,a[21]; 
	scanf("%d",&T); 
	if(T>=1 && T<50) 
	for(i=1;i<=T;i++) { 
		mile=juice=0; 
		scanf("%d",&N); 
		if(N>0 && N<20) 
		for(j=0;j<N;j++) scanf("%d",&a[j]); 
		for(j=0;j<N;j++) 
		{	 
			if(a[j]>=30) 
			{ 	
				A=0;B=0; 
				A=(a[j]+1)/30; 
				B=((a[j]+1)-(30*A)); 
				if(B>0) B=10; 
				mile=mile+(A*10)+B; 
			} 
		else mile=mile+10; 
		} 
		for(j=0;j<N;j++) { 
			if(a[j]>=60) { 
				A=0;B=0; 
				A=(a[j]+1)/60; 
				B=((a[j]+1)-(60*A)); 
				if(B>0) B=15; 
				juice=juice+(A*15)+B; 
			} 
		else juice=juice+15; 
		} 
		if(mile==juice) printf("Case %d: Mile Juice %d\n",i,mile);  
		else if(mile>juice) printf("Case %d: Juice %d\n",i,juice); 
		else printf("Case %d: Mile %d\n",i,mile);	 
	} 
}
