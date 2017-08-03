#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAX 35
void is_prime();
bool seev[MAX];

int main()
{
    is_prime();
    int num;
    long long sum;
    while(scanf("%d",&num) && num)
    {
        if(seev[num] == true)
        {
            printf("Given number is NOT prime! NO perfect number is available.\n");
        }
        else
        {
            if(num == 11 || num == 23 || num == 29 )
            {
                printf("Given number is prime. But, NO perfect number is available.\n");
            }
            else
            {
                sum = pow(2,num - 1) * ( pow(2,num) - 1);
                printf("Perfect: %lld!\n",sum);
            }
        }
    }
    return 0;
}
void is_prime()
{
    for(int i = 2 ; i < sqrt(MAX) ; i++)
    {
        if(i == 2 || seev[i] == false)
        {
            for(int j = i + i ; j < MAX ; j = j + i)
            {
                seev[j] = true;
            }
        }
    }
}
