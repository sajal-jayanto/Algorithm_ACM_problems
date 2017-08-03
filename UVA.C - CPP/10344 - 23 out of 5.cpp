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
#define MAX 10

using namespace std;
int have[MAX];
bool back_tracking(int r , int sum);
bool flage;

int main()
{
    while(scanf("%d %d %d %d %d",&have[0], &have[1] ,&have[2] ,&have[3] , &have[4])&& (have[0] || have[1] || have[2] || have[3] || have[4]))
    {
        flage = false;
        back_tracking(1 , have[0]);
        sort(have , have + 5);
        do{

            if(back_tracking(1 , have[0]))
            {
                flage = true ;
                break;
            }
        }
        while(next_permutation(have , have + 5));
        if(flage) printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}

bool back_tracking(int r , int sum)
{
    if(r == 5)
    {
        if(sum == 23)  return 1 ;
        else return 0;
    }
    return ( back_tracking(r + 1 , sum + have[r]) || back_tracking(r + 1 , sum - have[r]) || back_tracking(r + 1 , sum * have[r]));
}
