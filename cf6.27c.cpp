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
void solve()
{
    int n;
    cin>>n;
    vector<ll>  ans(n + 1);
    vector<PL> ret;
    for (int i = 0; i < n; i++)
    {
        static ll a, b;
        cin >> a >> b;
        ret.push_back({a, -1});
        ret.push_back({b, 1});
    }
    sort(ret.begin(), ret.end());
    ll pre = -1, now = 0;
    for (auto& t : ret)
    {
        if (t.second == -1)
        {
            if (~pre) ans[now] += t.first - pre;
            pre = t.first;
            now++;
        }
        else
        {
            if (pre <= t.first) ans[now] += t.first - pre + 1;
            pre = t.first + 1;
            now--;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
