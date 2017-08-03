#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

bool BFS(int a , map < int , vector < int > > temp);
map < int , char > visit;

int main()
{
    map < int , vector < int > > bord;
    int n,t;
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&t);
        int a , b;
        while(t--)
        {
            scanf("%d %d",&a,&b);
            bord[a].push_back(b);
            bord[b].push_back(a);
        }
        if(BFS(0 , bord)) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
        bord.clear();
    }
    return 0;
}


bool BFS(int a , map < int , vector < int > > temp)
{
    visit.clear();
    queue < int > Q;
    Q.push(a);
    visit[a] = 'r';
    while(!Q.empty())
    {
        int n = Q.front();
        Q.pop();
        int len = temp[n].size();
        for(int i = 0 ; i < len ; i++)
        {
            int m = temp[n][i];
            if(visit[m] == '\0')
            {
                if(visit[n] == 'r') visit[m] = 'b';
                else visit[m] = 'r';
                Q.push(m);
            }
            else if(visit[m] == visit[n]) return false;
        }
    }
    return true;
}
