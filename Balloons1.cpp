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
ll a;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(a!=0)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
