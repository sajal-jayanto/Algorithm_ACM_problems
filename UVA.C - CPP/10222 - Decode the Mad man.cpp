#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define  MAX 5000
char a[MAX];
char give[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`1234567890-=[]\\;',./";
char prin[] = "  czaqsdfyghjbvui w etx  r  czaqsdfyghjbvui w etx  r   `1234567890op[klnm,";
int main()
{
    gets(a);
    for(int i = 0 ; i < strlen(a) ; i++)
    {
        for(int j = 0 ; j < strlen(give) ; j++)
        {
            if(a[i] == give[j]) printf("%c",prin[j]);
        }
    }
    printf("\n");
    return 0;
}
