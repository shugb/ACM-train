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
int n;
int a[1001];
int b[1001];
int main()
{
    int s2;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==1)
        cout<<-1<<endl;
    else if(n==2&&(a[0]==a[1]))
            cout<<-1<<endl;
    else
    {
        b[0]=a[0];
        for(int i=1;i<n;i++)
            {
                b[i]+=b[i-1]+a[i];
            }
        for(int i=0;i<n;i++)
        {
            if((b[n-1]-b[i])!=b[i])
            {
                s2=i;
                break;
            }
        }
            cout<<s2+1<<endl;
        for(int i=0;i<=s2;i++)
        {
            cout<<i+1<<" ";
        }
    }
     return 0;
}
