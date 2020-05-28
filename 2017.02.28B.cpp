//#define LOCAL
#include<iostream>
#include<cstdio>
#include<cmath>
#define INF 10000000000
#define MAXN 40000
#define BASE 10000
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#define LL long long
using namespace std;
long long power(long long a, long long b,long long m)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%m;
            b--;
        }
        b/=2;
        a=a*a%m;
    }
    return ans;
}
int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // LOCAL
    int t;
    long long a; long long b;
    long long m;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>m;
       cout<<power(a,b,m)<<endl;
    }
    return 0;
}
