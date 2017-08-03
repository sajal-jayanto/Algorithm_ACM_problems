#include <bits/stdc++.h>

using namespace std;

#define pf printf
#define sf scanf


int main()
{
    int t , d , i , k ;
    while(sf("%d" , &t) && t != -1)
    {
        while(t--)
        {
            k = 1;
            sf("%d %d" , &d , &i);
            for(int l = 1 ; l < d ; l++)
            {
                if(i & 1)
                {
                    k <<= 1;
                    i = (i + 1) >> 1;
                }
                else
                {
                    k <<= 1; k++;
                    i >>= 1;
                }
            }
            pf("%d\n" , k);
        }
    }
    return 0;
}
