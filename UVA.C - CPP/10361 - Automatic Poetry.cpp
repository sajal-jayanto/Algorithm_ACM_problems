#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    //freopen("output.txt","w",stdout);
    char  frist[150],second[150],cp1[20],cp2[20],cp3[20];
    int t,i,k;
    scanf("%d",&t);
    gets(frist);
    while(t--)
    {
        gets(frist);
        gets(second);
        for(i = 0 ; i < strlen(frist) ; i++)
        {
            if(frist[i] == '<' || frist[i] == '>');
            else printf("%c",frist[i]);
        }
        printf("\n");
        for(i = 0 ; i < strlen(second) ; i++)
        {
            if(second[i] == '.') break;
            else printf("%c",second[i]);
        }
        for(i = 0 ; i < strlen(frist); i++ )
        {
            if(frist[i] == '<') break;
        }
        k = 0;
        while(frist[++i] != '>') cp1[k++] = frist[i];
        cp1[k] = '\0';k = 0;
        while(frist[++i] != '<') cp3[k++] = frist[i];
        cp3[k] = '\0';k = 0;
        while(frist[++i] != '>') cp2[k++] = frist[i];
        cp2[k] = '\0';k = 0;
        printf("%s",cp2);
        printf("%s",cp3);
        printf("%s",cp1);
        while(frist[++i] != '\0') printf("%c",frist[i]);
        printf("\n");
    }
    return 0;
}

