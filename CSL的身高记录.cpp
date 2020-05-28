//#define LOCAL
#include<iostream>
#include<cstdio>
#include<cmath>
#define INF 10000000000
#include<cstring>
#include<algorithm>
#include<algorithm>
#include <iomanip>
#define offset 10000
#define eps 1e-5
#define LL long long
using namespace std;
int a[40005];
int d[40005];
int n,m;
int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // LOCAL
    int i,j,k;
    while(scanf("%d %d",&n,&m)==2)
    {
         for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if (m==n-1)
    {
    cout<<"Yes"<<endl;
    }
    else
    {
    d[1]=a[1];
    int len=1;
    for (int i=2;i<=n;i++)
    {
        if (a[i]>=d[len]) d[++len]=a[i];
        else
        {
            int j=upper_bound(d+1,d+len+1,a[i])-d;
            d[j]=a[i];
        }
    }
    if(n-len<=m)
    cout<<"Yes"<<endl;
else
    cout<<"No"<<endl;
    }
    }
    return 0;
}
