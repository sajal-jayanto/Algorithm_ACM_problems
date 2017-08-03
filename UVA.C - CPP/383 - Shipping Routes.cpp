#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;
int BFS(string a , string b , map < string , vector < string > > bord);
map < string , int > visit;


int main()
{
   // freopen("output.txt","w",stdout);
    int t,cnt = 0;
    map < string , vector < string > > bord;
    scanf("%d",&t);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    while(t--)
    {
        bord.clear();
        printf("DATA SET  %d\n\n", ++ cnt);
        int a , b , c;
        scanf("%d %d %d",&a,&b,&c);
        getchar();
        string temp1 , temp2;
        while(a--) cin >> temp1;
        while(b--)
        {
            cin >> temp1 >> temp2;
            bord[temp1].push_back(temp2);
            bord[temp2].push_back(temp1);
        }
        while(c--)
        {
            scanf("%d",&a); cin >> temp1 >> temp2;
            b = BFS(temp1 , temp2 , bord);
            if(b == 0) printf("NO SHIPMENT POSSIBLE\n");
            else printf("$%d\n", (a * 100 * b));
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}

int BFS(string a , string b , map < string , vector < string > > bord)
{
    visit.clear();
    queue < string > Q;
    Q.push(a);
    visit[a] = 0;
    while(!Q.empty())
    {
        string s = Q.front();
        Q.pop();
        if(s == b) return visit[s];
        int len = bord[s].size();
        for(int i = 0 ; i < len ; i++)
        {
            string x = bord[s][i];
            if(visit[x] == 0)
            {
                visit[x] = visit[s] + 1;
                Q.push(x);
            }
        }
    }
    return 0;
}


