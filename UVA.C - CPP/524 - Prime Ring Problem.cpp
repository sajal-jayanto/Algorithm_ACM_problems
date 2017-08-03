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
#define MAX 50

using namespace std;
void is_prime();
void back_traking(int a , int n);
bool sive[MAX];
vector < int > print;
set < int > have;
set < int >::iterator it;


int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    is_prime();
    int num , cc = 0;
    while(scanf("%d",&num) == 1)
    {
        if(cc != 0) printf("\n");
        printf("Case %d:\n", ++cc);
        print.push_back(1);
        have.insert(1);
        back_traking( 1 , num);
        print.clear();
        have.clear();
    }
    return 0;
}

void back_traking(int a , int n)
{
    if(a == n )
    {
        printf("%d",print[0]);
        for(int i = 1 ; i < n ; i++) printf(" %d",print[i]);
        printf("\n");
        return ;
    }
    for(int i = 2 ; i <= n ; i++)
    {
        it = have.find(i);
        if((sive[ print[a - 1] + i ] == 0) && it == have.end())
        {
            if(print.size() == n - 1)
            {
                if(sive[i + 1] == 0)
                {
                    print.push_back(i);
                    have.insert(i);
                    back_traking(a + 1 , n);
                    have.erase(print.back());
                    print.pop_back();
                }
            }
            else
            {
                print.push_back(i);
                have.insert(i);
                back_traking(a + 1 , n);
                have.erase(print.back());
                print.pop_back();
            }

        }
    }
}

void is_prime()
{
    for(int i = 2 ; i < sqrt(MAX) ; i++)
        for(int j = i + i ; j < MAX ; j = j + i)
                sive[j] = true;
    sive[0] = sive[1] = true;
}
