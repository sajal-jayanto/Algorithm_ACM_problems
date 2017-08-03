#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int t,num,n,temp,count = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&num);
        printf("Case %d:",++count);
        n = sqrt(num);
        for(int i = n ; i > 0 ; i--)
        {
            temp = num - i * i;
            if((temp % i == 0) && (temp >= i))
            {
                printf(" %d",temp);
            }
        }
        printf("\n");
    }
    return 0;
}
