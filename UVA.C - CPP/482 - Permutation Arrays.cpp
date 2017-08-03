#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

struct take{

    int num;
    char fnum[30];

} take[MAX];

char str[MAX];


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,k;
    int high,low;
    char *p;
    scanf("%d",&t);
    gets(str);
    while(t--)
    {
        gets(str);
        gets(str);
        p = strtok(str , " ");
        k = 0;
        high = low = atoi(p);
        while(p != '\0')
        {
            take[k].num = atoi(p);
            p = strtok('\0' , " ");
            if(low > take[k].num) low = take[k].num;
            if(high < take[k].num) high = take[k].num;
            k++;
        }
        k = 0;
        gets(str);
        p = strtok(str," ");
        while(p != '\0')
        {
            strcpy(take[k++].fnum , p);
            p = strtok('\0' , " ");
        }
        for(int i = low ; i <= high ; i++)
        {
            for(int j = 0 ; j < k ; j++)
            {
                if(i == take[j].num)
                {
                    printf("%s\n",take[j].fnum);
                }
            }
        }
        if(t != 0) printf("\n");
    }
    return 0;
}
