#include <bits/stdc++.h>


#define sf scanf
#define pf printf

using namespace std;

vector < string > ve;
set < string > se;
string temp ;

int main()
{
    freopen("input.txt" , "r" , stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(false);  cout.tie(false);
    int t , n , m , cc = 0 ;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        cin.ignore();
        for(int i = 0 ; i < n ; ++i)
        {
            getline(cin , temp);
            ve.push_back(temp);
        }
        for(int i = 0 ; i < m ; ++i)
        {
            getline(cin , temp);
            for(int j = 0 ; j < n ; ++j) se.insert(ve[j] + temp);
        }
        cout << "Case "  << ++cc << ": "  << (int) se.size() << endl;
        ve.clear();
        se.clear();
    }
    return 0;
}
