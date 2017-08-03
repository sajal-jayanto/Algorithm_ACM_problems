#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int d1,m1,y1,d2,m2,y2,age,count = 0;
    int t;
    char ch;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%c%d%c%d",&d2,&ch,&m2,&ch,&y2);
        scanf("%d%c%d%c%d",&d1,&ch,&m1,&ch,&y1);
        if(d1 > d2)
        {
            d2 = d2 + 30;
            m1 = m1 + 1;
        }
        if(m1 > m2)
        {
            m2 = m2 + 12;
            y1++;
        }
        age = y2 - y1;
        if(age < 0)
        {
            printf("Case #%d: Invalid birth date\n",++count);
        }
        else if(age > 130)
        {
            printf("Case #%d: Check birth date\n",++count);
        }
        else printf("Case #%d: %d\n",++count,age);
    }
    return 0;
}
