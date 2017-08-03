#include<bits/stdc++.h>
using namespace std;

bool pr[100005];
long long  p[10000];
long long sz=0;

vector < long long > ve[1325];

bool ps(long long n) {
    if (n < 0)
        return false;
    long long root(round(sqrt(n)));
    return n == root * root;
}

void sieve(){
    pr[1]=pr[0]=1;
    for(long long  i=3; i<=317; i+=2){
        if(!pr[i]){
            for(long long j=i*i; j<=100000; j+=2*i){
                pr[j]=1;
            }
        }
    }
    p[sz++]=2;
    for(long long i=1; i<100000; i+=2){
        if(!pr[i]) p[sz++]=i;
    }
}

void calc(){
    for(long long i=1; i<=100000; i++) {
        long long cnt=1;
        long long tmp=i;
        for(int j = 0 ; p[j] * p[j] <= tmp ; ++j)
        {
            if(tmp % p[j] == 0)
            {
                long long x = 0;
                while(tmp % p[j] == 0)
                {
                    ++x;
                    tmp = tmp / p[j];
                }
                cnt*=(2*x+1);
            }
        }
        if(tmp != 1) cnt = cnt * 3;
        ve[cnt].push_back(i * i);
    }
}

int main(){
    sieve();
    calc();
    long long t;
    scanf("%lld", &t);
    while(t--){
        long long k;
        long long a, b;
        long long ans=0;
        scanf("%ld %lld %lld", &k, &a, &b);
        printf("%d\n" , upper_bound(ve[k].begin() , ve[k].end() , b) - lower_bound(ve[k].begin() , ve[k].end() , a));
    }
    return 0;
}
