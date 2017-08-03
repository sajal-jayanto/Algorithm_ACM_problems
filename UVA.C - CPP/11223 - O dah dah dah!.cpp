#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
char simble[][10] = {  ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
      "--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",
	  "-----",".----","..---","...--","....-",".....","-....","--...","---..","----.",".-.-.-",
	  "--..--","..--..",".----.","-.-.--","-..-.","-.--.","-.--.-",".-...","---...","-.-.-.","-...-",
	  ".-.-.","-....-","..--.-",".-..-.",".--.-."
};
char cha[][2] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U",
				  "V","W","X","Y","Z","0","1","2","3","4","5","6","7","8","9",".",",","?","'","!","/",
				  "(",")","&",":",";","=","+","-","_"," ","@"
};
int main()
{
	//freopen("output.txt","w",stdout);
	int t,k,count = 0;
	char ar = '"';
	char input[2010];
	char chak[10];
	scanf("%d",&t);
	gets(input);
	while(t--)
	{
		gets(input);
		k = 0;
		if(count!=0) printf("\n");
		printf("Message #%d\n",++count);
		for(int i = 0 ; i < strlen(input) ; i++)
		{
			if(input[i] == ' ')
			{
				chak[k] = '\0';
				if(k == 0) printf(" ");
				for(int j = 0; j <= 52 ; j++)
				{
					if(strcmp(simble[j],chak) == 0)
					{
						if(j != 51) printf("%s",cha[j]);
						else printf("%c",ar);
							break;
					}
				}
				k = 0;	
			}
			else chak[k++] = input[i];
		}
		chak[k] = '\0';
		for(int j = 0; j <= 52 ; j++)
		{
			if(strcmp(simble[j],chak) == 0)
			{
				if(j != 51) printf("%s",cha[j]);
				else printf("%c",ar);
					break;
			}
		}
		printf("\n");
	}
	return 0;	
}
