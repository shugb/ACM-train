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
int main()
{
    ios::sync_with_stdio(false);
    int t;
    ll a,b;
    float d;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>d;
        cout<<fixed<<setprecision(6)<<d/2.0*d<<endl;
    }
    return 0;
}
