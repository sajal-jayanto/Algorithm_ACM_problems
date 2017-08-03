#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
    char ar[20];
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        int k = 0;
        for(int i = 0 ; i < a - b ; i++) ar[k++] = '0';
        for(int i = 0 ; i < b ; i++) ar[k++] = '1';
        ar[k] = '\0';
        printf("%s\n",ar);
        while(next_permutation(ar , ar + k))
            printf("%s\n",ar);
        if(t) printf("\n");
    }
    return 0;
}
