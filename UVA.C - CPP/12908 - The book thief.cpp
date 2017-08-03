#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;


int main()
{
    long long num , temp ;
    while(sf("%lld" , &num) && num)
    {
        temp = 1;
        for(long long i = 2 ; ; ++i)
        {
            temp = temp + i;
            if(temp > num)
            {
                pf("%lld %lld\n" , temp - num , i);
                break ;
            }
        }
    }
    return 0;
}
