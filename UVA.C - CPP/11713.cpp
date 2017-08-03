#include<stdio.h>
#include<string.h>
int is_vowel(char);
int main()
{
	int t,i,count;
	char frist[30],second[30];
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(frist);
		gets(second);
		count = 0;
		if(strlen(frist)==strlen(second))
		{
			for(i=0;i<strlen(frist);i++)
			{
				if(frist[i]!=second[i])
				{
					if((is_vowel(frist[i])==0) && (is_vowel(second[i])==0))  
					count = count+0;
					else
					{
						count = count+1;
							break;
					} 
					
				}	
			}
			if(count!=0) printf("No\n");
			else printf("Yes\n");
		}
		else printf("No\n");	
	}
	return 0;
}
int is_vowel(char ch)
{
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
	{
		return 0;
	}
	else return 1;
}
