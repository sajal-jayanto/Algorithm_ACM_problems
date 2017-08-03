#include<stdio.h>
int main()
{
    char ch;
    int i=0;
    while(( ch = getc(stdin) ) != EOF)
    {
         if((int)ch==34)
         {
            if (i==0)
            {
                printf("``");
                    i=1;
            }
            else if(i==1)
            {
                printf("''");
                	i=0;
            }
         }
         else printf("%c",ch);
    }
    return 0;
}
