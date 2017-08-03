#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

deque < int > DQ;
vector < int > ve;

bool is_sort(int n)
{
    for(int i = 0 ; i < n ; ++i) if(DQ[i] != i + 1) return false;
    return true;
}

int main()
{
    //freopen("input.txt" , "r" , stdin);
    int t , n , temp ;
    while(sf("%d" , &t) && t)
    {
        for(int i = 0 ; i < t ; ++i)
        {
            sf("%d" , &n);
            DQ.push_back(n);
        }
        while(!is_sort(t))
        {
            if(DQ[0] >  DQ[1] && DQ[0] != t) { swap(DQ[0] , DQ[1]); ve.push_back(1) ; }
            else { temp = DQ.back(); DQ.pop_back(); DQ.push_front(temp); ve.push_back(2); }
        }
        for(int i = ve.size() - 1 ; i >= 0 ; i--) pf("%d" , ve[i]);
        pf("\n");
        ve.clear();
        DQ.clear();
    }
    return 0;
}
