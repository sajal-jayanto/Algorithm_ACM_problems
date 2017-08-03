#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    int r,c,m,n,p,count = 0;
    int num[30];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&r,&c,&m,&n);
        char ar[c + 5];
        memset(num , 0 , sizeof(num));
        for(int i = 0; i < r; i++)
        {
            scanf("%s",ar);
            for(int j = 0 ; j < strlen(ar) ; j++)
            {
                num[ar[j] - 65]++;
            }
        }
        r = c = p = 0;
        for(int i = 0 ; i < 26 ; i++)
        {
            r = r + num[i];
            if(c < num[i]) c = num[i];
        }
        for(int i = 0 ; i < 26 ; i++)
        {
            if(num[i] == c)
            {
                r = r - c;
                p = p + c;
            }
        }
        p = p * m;
        r = r * n;
        printf("Case %d: %d\n",++count,p + r);
    }
    return 0;
}
