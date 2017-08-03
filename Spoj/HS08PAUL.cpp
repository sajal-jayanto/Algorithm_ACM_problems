#include<bits/stdc++.h>
#define sf scanf
#define pf printf

using namespace std;

bool sive[10000100];
vector < int > prime;
vector < int > two ;
vector < int > four ;

void is_prime()
{
    sive[0] = sive[1] = true;
    int k = sqrt(10000100);
    for(int i = 4 ; i < 10000100 ; i = i + 2) sive[i] = true;
    for(int i = 3 ; i <= k ; i = i + 2)
    {
        if(!sive[i]) for(int j = i * i ; j < 10000100 ; j = j + (2 * i)) sive[j] = true;
    }
}

int main()
{
    is_prime();
    int temp;
    for(long long i = 1 ; ; ++i)
    {
        temp = i * i;
        if(temp > 10000100) break;
        two.push_back(temp);
    }
    for(int i = 1 ; ; ++i)
    {
        temp = (i * i * i * i);
        if(temp > 10000100) break;
        four.push_back(temp);
    }
    int sum ;
    for(auto x : two)
    {
        for(auto y : four)
        {
            sum = x + y;
            if(sum >= 10000010) break;
            if(!sive[sum])
            {
                prime.push_back(sum) ;
                sive[sum] = true;
            }
        }
    }
    sort(prime.begin() , prime.end());
    int t , num , pos ;
    sf("%d" , &t);
    while(t--)
    {
        sf("%d" , &num);
        pos = upper_bound(prime.begin() , prime.end() , num) - prime.begin();
        pf("%d\n" , pos);
    }
    return 0;
}
