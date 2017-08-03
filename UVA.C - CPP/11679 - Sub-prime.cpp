#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

int main()
{

    int money[30];
    int bank,debentures;
    int a,b,c;
    while(scanf("%d %d",&bank,&debentures) && ( bank || debentures ))
    {
        for(int i = 0 ; i < bank ; i++)
        {
            scanf("%d",&money[i]);
        }
        for(int i = 0 ; i < debentures ;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            money[b - 1] = money[b - 1] + c;
            money[a - 1] = money[a - 1] - c;
        }
        for(int i = 0 ; i< bank ; i++)
        {
            if(money[i] < 0)
            {
                printf("N\n");
                continue;
            }
        }
        printf("S\n");
    }
    return 0;
}
