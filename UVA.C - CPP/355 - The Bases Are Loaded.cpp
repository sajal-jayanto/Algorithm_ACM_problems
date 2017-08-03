#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
char made(int);
int chak(char);
char ar[50];
char ans[50];
int main()
{
	int have,doin,k,dig;
	long long num;
	char *p;
	while(scanf("%d %d %s",&have,&doin,ar) == 3)
	{
		k = 0;
		for(int i = 0 ;i < strlen(ar) ; i++)
		{
			if( chak(ar[i]) < have ) k =  0; 
			else
			{
				k =  1;
				break;
			} 
		}
		if(k == 0)
		{
			printf("%s base %d = ",ar,have);
			k = 0;
			num = strtol(ar,&p,have);
			if(num == 0) printf("0");
			while(num)
			{
				dig = num % doin;
				num = num / doin;
				ans[k++] = made(dig);		
			}	
			for(int i = k - 1; i >= 0 ; i--) printf("%c",ans[i]);
			printf(" base %d\n",doin);
		}
		else printf("%s is an illegal base %d number\n",ar,have);
	
	}
	return 0;
}
char made(int num)
{
	if(num == 0) return '0';
	else if(num == 1) return '1';
	else if(num == 2) return '2';
	else if(num == 3) return '3';
	else if(num == 4) return '4';
	else if(num == 5) return '5';
	else if(num == 6) return '6';
	else if(num == 7) return '7';
	else if(num == 8) return '8';
	else if(num == 9) return '9';
	else if(num == 10) return 'A';
	else if(num == 11) return 'B';
	else if(num == 12) return 'C';
	else if(num == 13) return 'D';
	else if(num == 14) return 'E';
	else if(num == 15) return 'F';
}
int chak(char ch)
{
	if(ch == '0') return 0;
	else if(ch == '1') return 1;
	else if(ch == '2') return 2;
	else if(ch == '3') return 3;
	else if(ch == '4') return 4;
	else if(ch == '5') return 5;
	else if(ch == '6') return 6;
	else if(ch == '7') return 7;
	else if(ch == '8') return 8;
	else if(ch == '9') return 9;
	else if(ch == 'A') return 10;
	else if(ch == 'B') return 11;
	else if(ch == 'C') return 12;
	else if(ch == 'D') return 13;
	else if(ch == 'E') return 14;
	else if(ch == 'F') return 15;
}
