#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int t;
	char c;
	scanf("%d\n",&t);
	while((c = getchar())!=EOF)
	{
		if(c=='1')      printf("I");
		else if(c=='2') printf("Z"); 
		else if(c=='3') printf("E");
		else if(c=='4') printf("A");
		else if(c=='5') printf("S");
		else if(c=='6') printf("G");
		else if(c=='7') printf("T");
		else if(c=='8') printf("B");
		else if(c=='9') printf("P");
		else if(c=='0') printf("O");
		else  printf("%c",c);	
	}
	return 0;
}
