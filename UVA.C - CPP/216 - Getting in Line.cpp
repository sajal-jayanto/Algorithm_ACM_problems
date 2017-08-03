#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

struct point {
    double x , y;
    point(double a , double b) { x = a; y = b; }
    point(){}
};
point ve[10];
int path[10];
double DP[10][10];

double dis(point a , point b)
{
    return sqrt( pow(b.x - a.x, 2) + pow(b.y - a.y , 2) ) + 16.00;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t ;
    double  total , mn ;
    int cc = 0;
    int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    point temp = point(0.00 , 0.00);
    while(sf("%d" , &t) && t)
    {
        mn = (1 << 30);
        for(int i = 0 ; i < t ; ++i) sf("%lf %lf" , &ve[i].x , &ve[i].y);
        for(int i = 0 ; i < t ; ++i) for(int j = 0 ; j < t ; ++j) if(i != j) DP[i][j] = dis(ve[i] , ve[j]);
        do
        {
            total = 0.00;
            for(int i = 1 ; i < t ; ++i) total = total + DP[ar[i - 1] - 1][ar[i] - 1];
            if(mn > total)
            {
                for(int i = 0 ; i < t ; ++i) path[i] = ar[i];
                mn = total;
            }

        } while(next_permutation(ar , ar + t));
        pf("**********************************************************\n");
        pf("Network #%d\n" , ++cc);
        for(int i = 1 ; i < t ; ++i)
        pf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n" ,
        (int)ve[path[i - 1] - 1].x , (int)ve[path[i - 1] - 1].y , (int)ve[path[i] - 1].x , (int)ve[path[i] - 1].y , DP[path[i - 1] - 1][path[i] - 1]);
        pf("Number of feet of cable required is %.2lf.\n" , mn);
    }
    return 0;
}
