#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n[10005];
int m[1005];
int m2[1005];
double k;
int n1,m1;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll ans=0;
        memset(n,0,sizeof(n));
        memset(m,0,sizeof(m));
        memset(m2,0,sizeof(m2));
        cin>>n1>>m1>>k;
        for(int i=1;i<=n1;i++)
        {
            cin>>n[i];
        }
        for(int i=1;i<=n1;i++)
        {
            m[n[i]]++;
        }
        for(int i=1;i<=floor(n1/2);i++)
        {
            m2[n[i]]++;
        }
        for(int i=1;i<=m1;i++)
        {
            ans+=min((int)floor((double)m[i]/k),m2[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
