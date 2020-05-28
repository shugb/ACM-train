#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll casenum,num,mmax,a[100005],p[100005],sum;
bool isprime[1000005];
int vis[1000005];
void init()
{
    isprime[1]=false;
    for(int i=2;i<=1000005;i++)
    {
        if(isprime[i])
            for(int j=2;i*j<=1000005;j++)
                isprime[i*j]=false;
    }
}
int main()
{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>casenum;
    while(casenum--)
    {
        memset(vis,0,sizeof(vis));
        sum=0;
        int cnt=0;
        cin>>num;
        for(int i=0;i<num;i++)
            cin>>a[i];
        sort(a,a+num);
        if(a[0]==1) cout<<num<<endl;
        else
        {
            for(int i=0;i<num;i++)
            {
                if(vis[a[i]]==0)
                {
                if(isprime[a[i]]) p[cnt++]=a[i],sum+=a[i],vis[a[i]]=a[i];
                else
                {
                    int j;
                    for(j=0;j<cnt;j++)
                        if(a[i]%p[j]==0)
                        {
                            sum+=p[j];
                            vis[a[i]]=p[j];
                            break;
                        }
                        else if(a[i]<2*p[j])
                        {
                            p[cnt++]=a[i];sum+=a[i];vis[a[i]]=a[i];break;
                        }
                    if(j==cnt) p[cnt++]=a[i],sum+=a[i],vis[a[i]]=a[i];
                }
                }
                else
                    sum+=vis[a[i]];
            }
            cout<<sum<<endl;
        }
    }
}
