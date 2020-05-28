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
int a[101],b[101],c[101],d[101];
int n,B;
int main()
{
    int l=0,r=0,j=0,sum=0,s=0;
    ios::sync_with_stdio(false);
    cin>>n>>B;
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    for(int i=0,t=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%2!=0)
           l++;
        else
           r++;
        b[t]=l;
        c[t]=r;
        t++;
    }
    for(int i=0;i<n-1;i++)
    {
        if(b[i]==c[i])
        {
            d[j]=abs(a[i+1]-a[i]);
            j++;
        }
    }
    sort(d,d+j);
    for(int i=0;i<j;i++)
    {
        if(sum+d[i]>B)
            break;
        else
        sum+=d[i];
        s++;
    }
    cout<<s<<endl;
    return 0;
}
