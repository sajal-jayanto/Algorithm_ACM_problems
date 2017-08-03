#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char bord[20];
char kye;

int main()
{
    //freopen("output.txt","w",stdout);
    gets(bord);
    while(gets(bord))
    {
        if(strcmp(bord,"___________") == 0) break;
        kye = 0;
        if(bord[1] == 'o') kye = kye + 128;
        if(bord[2] == 'o') kye = kye +  64;
        if(bord[3] == 'o') kye = kye +  32;
        if(bord[4] == 'o') kye = kye +  16;
        if(bord[5] == 'o') kye = kye +  8;
        if(bord[7] == 'o') kye = kye +  4;
        if(bord[8] == 'o') kye = kye +  2;
        if(bord[9] == 'o') kye = kye +  1;
        printf("%c",kye);
    }
    return 0;
}
