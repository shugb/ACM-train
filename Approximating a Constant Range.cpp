#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include <ctime>
#include<queue>
#include<set>
#include<map>
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
#define Max 1000000000
int dp[500000];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int ans = 2;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin>>x;
        if(dp[x-1] > dp[x+1])
          ans = max(ans,i-max(dp[x+1],dp[x-2]));
        else
          ans = max(ans,i-max(dp[x+2],dp[x-1]));
        dp[x] = i;
    }
    cout<<ans;
    return 0;
}
