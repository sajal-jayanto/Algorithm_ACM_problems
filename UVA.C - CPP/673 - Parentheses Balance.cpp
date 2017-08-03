#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
char c[500];
int main()
{
	int t,k,l;
	char ch;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		l = k = 0;
		while(ch = getchar())
		{
			if(ch == '\n') break;
			else if(ch == '(' || ch == '[') c[k++] = ch;
			else if(ch == ')' || ch == ']') 
			{
				k = k - 1;
				if(k <= -1) l = l + 1;
				if(ch == ')' && c[k] == '(') l = l + 0;  
				else if(ch == ']' && c[k] == '[') l = l + 0;
				else  l = l + 1;  
			}	
		}
		if(l == 0 && k == 0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

