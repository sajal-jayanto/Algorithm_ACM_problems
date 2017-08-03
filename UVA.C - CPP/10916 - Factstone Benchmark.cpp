#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <algorithm>
#define MAX 300001


using namespace std;

int ar[MAX];
void do_it();

int main()
{
    do_it();
    int num,cnt;
    while(scanf("%d",&num) && num)
    {
        num = num - 1960;
        num = (int) num / 10;
        cnt = 4;
        while(num--) cnt = cnt << 1;
        for(int i = 1 ; i < MAX ; i++)
        {
            if(ar[i] > cnt)
            {
                printf("%d\n", i - 1);
                break;
            }
        }
    }
    return 0;
}


void do_it()
{
    ar[0] = 0;
    double a,b;
    b = 0.0;
    for(int i = 1 ; i < MAX ; i++)
    {
        a = b;
        b = a + (log10(i) / log10(2));
        ar[i] = floor(b) + 1;
    }
}
