#include <map>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector <long long> myvector;
    long long num;
    while(scanf("%lld",&num) == 1)
    {
        myvector.push_back(num);
        sort(myvector.begin(),myvector.end());
        if(myvector.size() % 2 == 0)
        {
            num = (myvector[myvector.size() / 2] + myvector[(myvector.size() / 2) - 1]) / 2;
            printf("%lld\n",num);
        }
        else printf("%lld\n",myvector[myvector.size() / 2]);
    }
    return 0;
}
