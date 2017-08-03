#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<algorithm>
#define MAX 7000
int binarysearch(long long searchkey, long long size);
long long ar[MAX];
using namespace std;
int main()
{
    long long n;
    long long k = 2;
    ar[1] = 1;
    for(int i = 1; i <= 5000 ; i++)
    {
        n = ar[i] * 2;
        if(binarysearch(n,k) == 0) ar[k++] =  n;
        n = ar[i] * 3;
        if(binarysearch(n,k) == 0) ar[k++] =  n;
        n = ar[i] * 5;
        if(binarysearch(n,k) == 0) ar[k++] =  n;
        n = ar[i] * 7;
        if(binarysearch(n,k) == 0) ar[k++] =  n;
        sort(ar, ar + k);
    }
    while(scanf("%lld",&n) && n)
    {
    	printf("The %lld",n);
    	if(n%10==1 && (n/10)%10!=1) printf("st");
        else if(n%10==2 && (n/10)%10!=1) printf("nd");
        else if(n%10==3 && (n/10)%10!=1) printf("rd");
        else printf("th");
    	printf(" humble number is %lld.\n",ar[n]);
    }
    return 0;
}
int binarysearch(long long key, long long size)
{
    int low = 0;
    int high = size - 1;
    int middle;
    while (low <= high)
    {
        middle = low + (high - low) / 2;
        if (key > ar[middle])  low = middle + 1;
        else if (key < ar[middle])  high = middle - 1;
        else return 1;
    }
    return 0;
}
