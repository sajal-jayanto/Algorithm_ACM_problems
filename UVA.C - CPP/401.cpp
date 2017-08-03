#include <stdio.h>
#include <string.h>
int mirrored (char);
int main()
{
	//freopen ("sajal.txt","w",stdout);
	char frist[100];
	char second[100];
	int i,j,P,M;
	while(scanf("%s",frist)!=EOF)
	{
		i=-1;
		j=0;
		M=0;
		while(frist[++i]!='\0');
		while(i)
		{
			second[j++]=frist[--i];
		}
		second[j]='\0';
		P = strcmp(frist,second);
		for(i=0;i<strlen(frist);i++)
		{
			if(mirrored(frist[i])==0)
				M=M+0;
			else M=M+1;
		}
		if(M==0)
		{
			for(i=0,j=(strlen(frist)-1);i<strlen(frist)/2,j>strlen(frist)/2;i++,j--)
			{
		    	if((frist[i]=='A' && frist[j]=='A')||(frist[i]=='E' && frist[j]=='3')||
			   		(frist[i]=='H' && frist[j]=='H')||(frist[i]=='I' && frist[j]=='I')||
			   		(frist[i]=='J' && frist[j]=='L')||(frist[i]=='L' && frist[j]=='J')||
			   		(frist[i]=='M' && frist[j]=='M')||(frist[i]=='O' && frist[j]=='O')||
			   		(frist[i]=='T' && frist[j]=='T')||(frist[i]=='U' && frist[j]=='U')||
		   	   		(frist[i]=='V' && frist[j]=='V')||(frist[i]=='W' && frist[j]=='W')||
			   		(frist[i]=='X' && frist[j]=='X')||(frist[i]=='Y' && frist[j]=='Y')||
			   		(frist[i]=='Z' && frist[j]=='5')||(frist[i]=='1' && frist[j]=='1')||
			   		(frist[i]=='2' && frist[j]=='S')||(frist[i]=='3' && frist[j]=='E')||
			   		(frist[i]=='5' && frist[j]=='Z')||(frist[i]=='8' && frist[j]=='8')||
			   		(frist[i]=='S' && frist[j]=='2')||(frist[i]=='Z' && frist[j]=='5'))
			    	M=M+0;
			   else
			   {
			   		M=M+1;
			   		break;
			   }
			}
		}
		else M = 1;
		
		if(P!=0 && M!=0)printf("%s -- is not a palindrome.\n\n",frist);
    	else if(M!=0 && P==0)printf("%s -- is a regular palindrome.\n\n",frist);
    	else if(M==0 && P!=0)printf("%s -- is a mirrored string.\n\n",frist);
		else if(M==0 && P==0)printf("%s -- is a mirrored palindrome.\n\n",frist);	
	}
	return 0;
}
int mirrored (char ch)
{
	if (ch=='A'||ch=='H'||ch=='J'||
		ch=='M'||ch=='T'||ch=='V'||
		ch=='X'||ch=='Z'||ch=='2'||
		ch=='5'||ch=='S'||ch=='E'||
		ch=='I'||ch=='L'||ch=='O'||
		ch=='U'||ch=='W'||ch=='Y'||
		ch=='1'||ch=='3'||ch=='8'||
		ch=='Z') return 0;
	else return 1;
}
