#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;
int gcd(int a , int b);
int lcm(int a , int b);
int main()
{
    int num;

    while(scanf("%d",&num) && num)
    {
        vector < int > div;
        int n = sqrt(num);
        for(int i = 1 ; i <= n ; i++)
        {
            if(num % i == 0)
            {
                if(num / i != i) div.push_back(num / i);
                div.push_back(i);
            }
        }
        n = div.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = i ; j < n  ; j++)
                if(lcm(div[i] , div[j]) == num) cnt++;

        printf("%d %d\n",num, cnt);
    }
    return 0;
}


int gcd(int a , int b)
{
    if(b == 0) return a;
    return gcd(b , a % b);
}

int lcm(int a , int b)
{
    return a / gcd(a , b) * b;
}
