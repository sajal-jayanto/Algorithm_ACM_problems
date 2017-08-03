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

using namespace std;

struct node{

    int a;
    int b;
    int c;

} num[1010];

int big_num(int);
int small_num(int);

int main()
{
    //freopen("output.txt", "w", stdout);
    int i;
    map < int , int > mymap;
    while(scanf("%d",&num[0].a) && num[0].a)
    {
        printf("Original number was %d\n",num[0].a);
        num[0].b = big_num(num[0].a);
        num[0].a = small_num(num[0].b);
        num[0].c = num[0].b - num[0].a;
        mymap[num[0].c]++;
        for(i = 1 ;  ; i++)
        {
            num[i].b = big_num(num[i - 1].c);
            num[i].a = small_num(num[i].b);
            num[i].c = num[i].b - num[i].a;
            if(mymap[num[i].c] == 0) mymap[num[i].c]++;
            else break;
        }
        i++;
        for(int j = 0 ; j < i ; j++) printf("%d - %d = %d\n" , num[j].b, num[j].a , num[j].c);
        printf("Chain length %d\n\n",i);
        mymap.clear();
    }
    return 0;
}
int big_num(int n)
{
    char str[15];
    int k = 0;
    while(n)
    {
        str[k++] = (n % 10) + 48;
        n = n / 10;
    }
    str[k] = '\0';
    sort(str , str + k);
    reverse(str , str + k);
    n = atoi(str);
    return n;
}

int small_num(int n)
{
    char str[15];
    int k = 0;
    while(n)
    {
        str[k++] = (n % 10) + 48;
        n = n / 10;
    }
    str[k] = '\0';
    sort(str , str + k);
    n = atoi(str);
    return n;
}
