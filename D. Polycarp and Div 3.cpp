#include<bits/stdc++.h>
using namespace std;
#define mst(ss,b) memset((ss),(b),sizeof(ss))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> PL;
#define maxn 120005
string a;
ll sum;
int j;
bool vis[maxn]={0};
void init(int a,int b)
{
    for(int i=a+1;i<=b;i++)
    {
        vis[i]=1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a;
    sum=0;
    j=0;
    int s=0;
    int b[a.length()]={-1};
    for(int i=0;i<a.length();i++)
    {
        if((int)a[i]%3==0)
        {
            vis[i]=1;
            b[j]=i;
            j++;
            sum++;
        }
    }
    for(int i=0;i<j;i++)
    {
        if(!vis[i])
        {
            for(int t=b[i];t<b[i+1];t++)
            {
                s=s*10+(int)a[t+1];
                if(s%3==0)
                {
                       sum++;
                       init(b[i],t);
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
