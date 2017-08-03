#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    //freopen("output.txt","w",stdout);
    int t,ar[130],count = 0;
    char ch,k;
    char frist[100],second[100];
    scanf("%d",&t);
    gets(frist);
    gets(frist);
    while(t--)
    {
        if(count != 0) printf("\n");
        for(int i = 0 ; i < 130 ; i++) ar[i] = 0;
        gets(frist);
        gets(second);
        printf("%s\n",second);
        printf("%s\n",frist);
        for(int i = 0 ; i < strlen(frist) ; i++)
        {
             ar[frist[i]] = second[i] - frist[i];
        }
        k = 32;
        while(ch = getchar())
        {
            if((k == '\n' && ch == '\n') ||ch == EOF) break;
            k = ch;
            if(ch == '\n')  printf("\n");
            else if(ar[ch] == 0) printf("%c",ch);
            else printf("%c",ar[ch] + ch);
        }
        count++;
    }
    return 0;
}
