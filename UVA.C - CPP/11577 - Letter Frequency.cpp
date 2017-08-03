#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char str[250];
    int t,num[30],count;
    scanf("%d",&t);
    gets(str);
    while(t--)
    {
        gets(str);
        for(int i = 97 ; i < 123 ; i++)
        {
            count = 0;
            for(int j = 0 ; j < strlen(str) ; j++)
            {
                if(i == tolower(str[j]))
                {
                    count++;
                }
            }
            num[i - 96] = count;
        }
        count = 0;
        for(int i = 1 ; i < 27 ; i++ )
        {
            if(count < num[i]) count = num[i];
        }
        for(int i = 1 ; i < 27 ; i++)
        {
            if(num[i] == count)
            {
                printf("%c",i + 96);
            }
        }
        printf("\n");
    }
    return 0;
}
