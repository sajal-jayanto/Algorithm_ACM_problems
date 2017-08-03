#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define PI (2 *  acos(0.0))
#define eps 1e-7
#define sf scanf
#define pf printf
#define ab(a) (((a) > 0) ? (a) : -(a))

using namespace std;


long long gcd(long long a , long long b) {  return !b ? a : gcd(b , a % b);  }

long long mulmod(long long a , long long b , long long c)
{
    long long x, y = a % c;
    while(b > 0)
    {
        if(b % 2 == 1) x = (x + y) % c;
        y = (y * 2) % c;
        b = b / 2 ;
    }
    return x % c;
}

int bord[3][3];


void updat(char ch)
{
    if(ch == 'a')
    {
        bord[0][0]++;
        bord[0][1]++;
        bord[1][0]++;
    }
    else if(ch == 'b')
    {
        bord[0][0]++;
        bord[0][1]++;
        bord[0][2]++;
        bord[1][1]++;
    }
    else if(ch == 'c')
    {
        bord[0][1]++;
        bord[0][2]++;
        bord[1][2]++;
    }
    else if(ch == 'd')
    {
        bord[0][0]++;
        bord[1][0]++;
        bord[1][1]++;
        bord[2][0]++;
    }
    else if(ch == 'e')
    {
        bord[0][1]++;
        bord[1][1]++;
        bord[2][1]++;
        bord[1][0]++;
        bord[1][2]++;
    }
    else if(ch == 'f')
    {
        bord[0][2]++;
        bord[1][1]++;
        bord[1][2]++;
        bord[2][2]++;
    }

    else if(ch == 'g')
    {
        bord[1][0]++;
        bord[2][0]++;
        bord[2][1]++;
    }
    else if(ch == 'h')
    {
        bord[2][0]++;
        bord[2][1]++;
        bord[1][1]++;
        bord[2][2]++;
    }
    else if(ch == 'i')
    {
        bord[1][2]++;
        bord[2][2]++;
        bord[2][1]++;
    }
}


int main()
{
    freopen("input.txt" , "r" , stdin);
    int len , cc = 0;
    char str[100000];
    while(gets(str))
    {
        memset(bord , 0 , sizeof(bord));
        len = strlen(str);
        for(int i = 0 ; i < len ; ++i) updat(str[i]);
        pf("Case #%d:\n", ++cc);
        for(int i = 0 ; i < 3 ; ++i) pf("%d %d %d\n" , bord[i][0] % 10 , bord[i][1] % 10 , bord[i][2] % 10);
    }
    return 0;
}
