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
    int t;
    ll a;
    cin>>t;
    while(t--)
    {
        cin>>a;
        cout<<sqrt(a/6)<<endl;
    }
    return 0;
}
