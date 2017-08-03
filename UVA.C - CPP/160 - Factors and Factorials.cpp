#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define MAX 101
#define MAXP 50
bool seev[MAX];
int prime[MAXP];
void is_prime();

int main()
{
    int num,i,k,j,n,count;
    is_prime();
    while(scanf("%d",& num) && num)
    {
        k = 0;
        for( i = 2 ; i <= num ; i++)
        {
            if(seev[i] == false)
            {
                prime[k++] = i;
            }
        }
        printf("%3d! =",num);
        for(i = 0 ; i < k ; i++)
        {
            count = 0;
            for(j = 2 ; j <= num ; j++)
            {
                n = j;
                while(n % prime[i] == 0)
                {
                    n = n / prime[i];
                    count++;
                }
            }
            if(i % 15 == 0 && i != 0 ) printf("\n      ");
            printf(" %2d",count);
        }
        printf("\n");
    }
    return 0;

}
void is_prime()
 {
     int i , j;

     for( i = 2 ; i <= sqrt(MAX) ; i++)
     {
         if(i == 2 || seev[i] == false)
         {
             for(int j = i + i ; j <= MAX ; j = j + i)
             {
                 seev[j] = true;
             }
         }
     }
 }
