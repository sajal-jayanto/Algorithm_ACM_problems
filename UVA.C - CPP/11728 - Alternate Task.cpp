#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
int sum_divider(int);
int main()
{

    int num,count = 0;
    bool flag;
    while(scanf("%d",&num) && num)
    {
        flag = false;
        for(int i = num ; i >= 0 ; i--)
        {
            if(sum_divider(i) == num)
            {
                printf("Case %d: %d\n",++count,i);
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            printf("Case %d: -1\n",++count);
        }
    }
    return 0;

}

int sum_divider(int num)
{
    int ans = 0;
    int n = sqrt(num);
    for(int i = 1 ; i <= n ; i++)
    {
        if(num % i == 0)
        {
            if(num / i != i)
            {
                ans = ans + i + (num / i);
            }
            else ans = ans + i;
        }
    }
    if(num == 1) return 1;
    return ans;
}

