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
#define MAX 15
using namespace std;
void back_traking(int a , int sum , int n, int t);
set < string > myset;
set < string >::iterator it;
int have[MAX];
vector < int > print;


int main()
{

    int n , t;
    while(scanf("%d %d", &n, &t) && (n || t))
    {
        for(int i = 0 ; i < t ; i++) scanf("%d", &have[i]);
        printf("Sums of %d:\n",n);
        back_traking(0 , 0 , n , t);
        if(myset.empty()) printf("NONE\n");
        myset.clear();
    }
    return 0;
}

void back_traking(int a , int sum , int n, int t)
{
    if(sum == n)
    {
        string temp;
        temp = temp + to_string(print[0]);
        for(int i = 1 ; i < print.size() ; i++) temp = temp + "+" + to_string(print[i]);
        it = myset.find(temp);
        if(it == myset.end()) myset.insert(temp) , printf("%s\n",temp.c_str());
    }
    for(int i = a ; i < t ; i++)
    {
        if(sum + have[i] <= n)
        {
            sum = sum + have[i];
            print.push_back(have[i]);
            back_traking(i + 1 , sum , n , t);
            sum = sum - have[i];
            print.pop_back();
        }
    }
}
