#include <bits/stdc++.h>
using namespace std;
vector < int > ve;
char y[3000];
int main()
{
    int t , k , x , ans , temp , len  ;
    scanf("%d" , &t);
    while(t--) {
        ans = 1; ve.clear();
        scanf("%d %s" , &x , y);
        len = strlen(y);  k = sqrt(x); ve.push_back(x);
        if(!x || (len == 1 && y[0] == '0')) { if(!x) printf("%s\n" , y); else printf("%d\n" , x); continue ; }
        for(int i = 2 ; i <= k ; ++i)  {
            if(x % i == 0) { ve.push_back(i);
                if(x / i != i) ve.push_back(x / i);
            }
        }sort(ve.rbegin() , ve.rend());
        for(int i = 0 ; i < ve.size() ; ++i){  temp = 0;
            for(int j = 0 ; j < len ; ++j) {
                temp = (temp * 10) + (y[j] - '0'); temp = temp % ve[i];
            } if(!temp) { ans = ve[i];  break ; }
        }printf("%d\n" , ans);
    }return 0;
}
