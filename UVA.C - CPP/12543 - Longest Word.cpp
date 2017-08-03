#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int i,count,lon = 0;
    char ch[80],word[50],hword[50];
    while(scanf("%s",ch) && (strcmp(ch ,"E-N-D") != 0))
    {
        count = 0;
        for(i = 0 ; i < strlen(ch); i++)
        {
            if((isalpha(ch[i]) != 0) || ch[i] == '-')
            {
                word[count++] = ch[i];
            }
        }
        word[count] = '\0';
        if(lon < count)
        {
            strcpy(hword , word);
            lon = strlen(hword);
        }
    }
    for(i = 0 ; i < strlen(hword) ; i++)
    {
        printf("%c",tolower(hword[i]));
    }
    printf("\n");
    return 0;
}
