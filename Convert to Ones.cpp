#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include <ctime>
#include<queue>
#include<set>
#include<list>
#include<stack>
#include<iomanip>
#include<cmath>
#include<bitset>
#define mst(ss,b) memset((ss),(b),sizeof(ss))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> PL;
#define Maxn 500000
string a;
int vis[300001];
ll x,y;
int n;
int main()
{
    ll sum=0;
    cin>>n>>x>>y;
    cin>>a;
    memset(vis,0,sizeof(vis));
    string b=a;
    for(int i=0;i<a.length();i++)
     {
         b[i]='1';
     }
    if(a[0]=='0')
        vis[0]=0;
    else
        vis[0]=1;
        for(int i=1,j=1;i<a.length();i++)
     {
         if(a[i]=='1')
         {
           vis[j]=vis[j-1]+1;
         }
         else
            vis[j]=vis[j-1];
         j++;
     }
    if(b==a)
        cout<<0<<endl;
    else
    {
    for(int i=0;i<n;i++)
    {
        if(a[i]=='0'&&a[i+1]=='1')
        {
            if((vis[n-1]-vis[i+1])!=n-i-2)
            {
            if(x<=y)
            {
                sum+=x;
            }
            else
            {
                sum+=y;
            }
            }
        }
    }
    sum+=y;
        cout<<sum<<endl;
    }
    return 0;
}
