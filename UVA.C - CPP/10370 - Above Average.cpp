#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main()
{
    int t,n,sum,count;
    int grd[1010];
    double avg;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum = 0;
        avg = 0.0;
        for(int i = 0 ; i < n ; i++)
        {
            scanf("%d",&grd[i]);
            sum = sum + grd[i];
        }
        sum = sum / n;
        for(int i = 0 ; i < n ; i++)
        {
            if(grd[i] > sum)
            {
                avg = avg + 100.00;
            }
        }
        avg = avg / (double) n;
        printf("%2.3lf%%\n",avg);
    }
    return 0;
}
