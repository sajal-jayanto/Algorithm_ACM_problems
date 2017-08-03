#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstring>
#include <string>
#include <map>

using namespace std;
long long powL(int n , int p);

int main()
{
    long long num;
    int n,p,cc =0;
    bool flage;
    while(scanf("%lld",&num) && num)
    {
        flage = false;
        if(num < 0)
        {
            num = num * -1;
            n = (int)sqrt(num);
            num = num * -1;
            for(int i = -2 ; i >= -n ; i--)
            {
                long long ans = 0;
                p = 1;
                while(ans > num) ans = powL(i , p++);
                if(ans == num)
                {
                    flage = true;
                    p--;
                    break;
                }
            }
            if(!flage) printf("Case %d: 1\n",++cc);
            else printf("Case %d: %d\n",++cc,p);
        }
        else
        {
            n = (int)sqrt(num);

            for(int i = 2 ; i <= n ; i++)
            {
                long long ans = 0;
                p = 1;
                while(ans < num) ans = powL(i , p++);
                if(ans == num)
                {
                    flage = true;
                    p--;
                    break;
                }
            }
            if(!flage) printf("Case %d: 1\n",++cc);
            else printf("Case %d: %d\n",++cc,p);
        }
    }
    return 0;
}
long long powL(int n , int p)
{
    if(p == 0) return 1;
    if(p % 2 == 0)
    {
        long long num = powL(n , p / 2);
        return num * num;
    }
    else return n * powL(n , p - 1);
}
