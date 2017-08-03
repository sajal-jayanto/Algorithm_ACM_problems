#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include <string.h>
int vowel(char);
int main()
{
    char ch,c;
    while(scanf("%c", &ch)!= EOF )
    {
        if(isalpha(ch))
        {
                if(vowel(ch) == 0)
                {
                    while(isalpha(ch))
                    {
                        printf("%c",ch);
                        ch = getchar();
                    }
                    printf("ay");
                }
                else
                {
                    c = ch;
                    ch = getchar();
                    while(isalpha(ch))
                    {
                        printf("%c",ch);
                        ch = getchar();
                    }
                    printf("%cay", c);
                }
        }
        putchar(ch);
    }
    return 0;
}
int vowel(char ch)
{
    if(ch=='A' ||
       ch=='E' ||
       ch=='I' ||
       ch=='O' ||
       ch=='U' ||
       ch=='a' ||
       ch=='e' ||
       ch=='i' ||
       ch=='o' ||
       ch=='u') return 0;
    return 1;
}
