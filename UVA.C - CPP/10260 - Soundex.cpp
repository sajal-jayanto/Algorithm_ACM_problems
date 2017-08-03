#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
char soundex(char);

int main()
{
    freopen("output.txt","w",stdout);
    char str[30];
    char ch,an;
    while(gets(str))
    {
        an = '\0';
        for(int i = 0 ; i < strlen(str) ; i++)
        {
            ch = soundex(str[i]);
            if(ch != '0')
            {
                if(an != ch)
                {
                    printf("%c",ch);
                    an = ch;
                }
            }
            else an = '\0';
        }
        printf("\n");
    }
    return 0;
}
char soundex(char ch)
{
    if(ch == 'A'||ch == 'E' ||ch == 'I' ||ch == 'O'||
       ch == 'U'||ch == 'H' ||ch == 'W' ||ch == 'Y' ) return '0';
    else
    {
        if(ch == 'B'||ch == 'F'||ch == 'P'||ch == 'V') return '1';
        else if(ch == 'C'||ch == 'G'||ch == 'J'||ch == 'K'||ch == 'Q'||ch == 'S'||ch == 'X'||ch == 'Z') return '2';
        else if(ch == 'D' || ch == 'T') return '3';
        else if(ch == 'L') return '4';
        else if(ch == 'M' ||ch == 'N') return '5';
        else if(ch == 'R') return '6';
    }
}
