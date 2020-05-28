#define LOCAL
#include<iostream>
#include<cstdio>
#include<cmath>
#define INF 10000000000
#include<cstring>
#include<algorithm>
#include <iomanip>
#define offset 10000
#define eps 1e-5
#define LL long long
using namespace std;
int a[101];
int dp[2500000];
int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // LOCAL
    int n;
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        for(int i=0;i<n;i++)
        {
            for(int k=sum;k>=a[i];k--)
            {
                dp[k]=max(dp[k],dp[k-a[i]]+a[i]);
            }
        }
        int mmin;
        for(int i=0;i<=sum;i++)
        {
            if(dp[i]&&abs(sum-dp[i]-dp[i])<mmin)
                mmin=abs(sum-dp[i]-dp[i]);
        }
        cout<<(sum-mmin)/2<<' '<<(sum-mmin)/2+mmin<<endl;
    }
    return 0;
}
