#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<algorithm>

using namespace std;

int main()
{
    int t,i,j,sum;
    char frist[250],second[250],ans[300];
    scanf("%d",&t);
    gets(frist);
    while(t--)
    {
        scanf("%s %s",frist,second);
        if(strlen(frist) > strlen(second))
        {
            i = strlen(second);
            while(i != strlen(frist)) second[i++] = '0';
            second[i] = '\0';
        }
        else if(strlen(frist) < strlen(second))
        {
            i = strlen(frist);
            while(i != strlen(second)) frist[i++] = '0';
            frist[i] = '\0';
        }
        reverse(frist , frist + strlen(frist));
        reverse(second , second + strlen(second));
        //printf("%s %s",frist,second);
        sum = i = 0;
        for(j = strlen(frist) - 1 ; j >= 0 ; j--)
        {
            sum = sum + ((frist[j] - 48) + (second[j] - 48));
            ans[i++] = ((sum % 10) + 48);
            sum = sum / 10;
        }
        if(sum != 0) ans[i++] = '1';
        ans[i] = '\0';
        i = 0;
        while(ans[i] == '0') i++;
        for(j = i ; j < strlen(ans) ; j++)
        {
            printf("%c",ans[j]);
        }
        printf("\n");
    }
	return 0;
}

