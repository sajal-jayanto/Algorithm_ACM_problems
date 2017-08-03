#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#define MAX 30

using namespace std;
void back_track(int a , int sum , int n , int t);
int have[MAX];
int valu;
vector < int > temp;
vector < int > print;

int main()
{
    //freopen("input.txt","r", stdin);
    int n,t;
    while(scanf("%d %d",&n, &t) == 2)
    {
        int sum = 0;
        valu = 0;
        for(int i = 0 ; i < t ; i++) scanf("%d",&have[i]);
        back_track(0 , 0 , n, t);
        for(int i = 0 ; i < print.size() ; i++) printf("%d ",print[i]), sum = sum + print[i];
        printf("sum:%d\n", sum);
        print.clear();
        temp.clear();
    }
    return 0;
}

void back_track(int a , int sum , int n , int t)
{
    if(sum > valu)
    {
        valu = sum;
        print = temp;
    }
    for(int i = a ; i < t ; i++)
    {
        if(sum + have[i] <= n)
        {
            sum = sum + have[i];
            temp.push_back(have[i]);
            back_track(i + 1 , sum , n , t);
            sum = sum - have[i];
            temp.pop_back();
        }
    }
}
