#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
{

    freopen("output.txt","w",stdout);
    int t,num,k;
    int bord[50];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&num);
        if(num == 0)
        {
            printf("0\n");
            continue;
        }
        if(num == 1)
        {
            printf("1\n");
            continue;
        }
        k = 0;
        for(int i = 9 ; i > 1 ; i--)
        {
            if(num % i == 0)
            {
                while(num % i == 0)
                {
                    num = num / i;
                    bord[k++] = i;
                }
            }
        }
        if(num == 1)
        {
            for(int i = k - 1 ; i >= 0 ; i--)
            {
                printf("%d",bord[i]);
            }
        }
        else printf("-1");

        printf("\n");
    }
    return 0;
}
