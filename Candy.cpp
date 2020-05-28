#define LOCAL
#include<iostream>
#include<cstdio>
#include<cmath>
#define INF 10000000000
#include<cstring>
#include<algorithm>
#include<algorithm>
#include <iomanip>
#include<string>
#define offset 10000
#define eps 1e-5
#define LL long long
using namespace std;
int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // LOCAL
    int n,m,a,b,c;
    cin>>n>>m;
    int t[100001]={0};
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        for(int i=a;i<=b;i++)
        {
            t[i]+=c;
        }
    }
    for(int i=1;i<n;i++)
    {
    cout<<t[i]<<" ";
    }
    cout<<t[n]<<endl;
    return 0;
}
