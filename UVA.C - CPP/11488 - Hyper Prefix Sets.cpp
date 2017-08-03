#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf

struct node {

    int dip , cnt ;
    node *next[3];
    node(int a , int b) { dip = a ; cnt = b; next[0] = next[1] = NULL;}

} *root ;
int mx = 0;

void insert(char *str , int len)
{
    node *p = root;
    int l ;
    for(int i = 0 ; i < len ; ++i)
    {
        l = str[i] - '0';
        if(p->next[l] == NULL) p->next[l] = new node(i + 1 ,  1);
        else p->next[l]->cnt++;
        mx = max(mx , p->next[l]->cnt * p->next[l]->dip);
        p = p->next[l];
    }
}

void del(node *p)
{
    for(int i = 0 ; i < 2 ; ++i) if(p->next[i]) del(p->next[i]);
    del(p);
}


int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t , n , len ;
    char str[1000];
    sf("%d" , &t);
    while(t--)
    {
        root = new node(0 , 0);
        mx = 0;
        sf("%d" , &n);
        for(int i = 0 ; i < n ; ++i)
        {
            sf("%s" , str);
            len = strlen(str);
            insert(str , len);
        }
        pf("%d\n" , mx);
    }
    return 0;
}
