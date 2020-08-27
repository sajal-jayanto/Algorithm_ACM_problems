#include <cstdio>

int main()
{
    long long number , ans ;
    while(scanf("%lld" , &number) == 1){
        number = (number / 2ll) + 1;
        ans = (number * (number + 1) ) / 2ll;
        printf("%lld\n" , ans);
    }

    return 0;
}
