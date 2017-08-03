#include <bits/stdc++.h>


#define sf scanf
#define pf printf
#define MAX 10010

using namespace std;

struct node {

    int num , sum;
    node(){}
    node(int a , int b) { num = a , sum = b; }
};

vector < node > ve;
bool sive[1000000];
int prime[1529111];

node is_plen(int num)
{
    int k , temp = num , rev = 0 , pro = 1;
    while(num)
    {
        k = (num % 10);
        if(k) pro = pro * k;
        rev = (rev * 10) + k;
        num = num / 10;
    }
    if(rev == temp) return node(1 , pro);
    return node(0 , 0);
}

int main()
{
    int cnt = 1;
    prime[cnt++] = 2;
    int k = sqrt(1000000);
    for(int i = 3 ; i <= k ; i = i + 2)
    {
        if(!sive[i]) for(int j = (i * i) ; j < 1000000 ; j = j + (2 * i)) sive[j] = true;
    }
    for(int i = 3 ; i < 1000000 ; i = i + 2) if(!sive[i]) prime[cnt++] = i;
    node temp ;
    for(int i = 1 ;  ; ++i)
    {
        temp = is_plen(prime[i]);
        if(temp.num) ve.push_back(node(prime[i] , prime[temp.sum]));
        if(ve.size() >= 113) break ;
    }
    int t;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &cnt);
        pf("%d %d\n" , ve[cnt - 1].num , ve[cnt - 1].sum);
    }
    return 0;
}
