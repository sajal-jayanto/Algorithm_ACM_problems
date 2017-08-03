#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<string.h>

using namespace std;

int main()
{
    int t,takr[7],count = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d %d %d",&takr[0],&takr[1],&takr[2],&takr[3],&takr[4],&takr[5],&takr[6]);
        sort(takr + 4 ,takr + 7);
        int ave = (takr[5] + takr[6]) / 2;
        int sum = (takr[0] + takr[1] + takr[2] + takr[3] + ave);
        if(sum < 60) printf("Case %d: F\n",++count);
        else if(sum >= 60 && sum < 70) printf("Case %d: D\n",++count);
        else if(sum >= 70 && sum < 80) printf("Case %d: C\n",++count);
        else if(sum >= 80 && sum < 90) printf("Case %d: B\n",++count);
        else if(sum >= 90) printf("Case %d: A\n",++count);
    }
    return 0;
}
