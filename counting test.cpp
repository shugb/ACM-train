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
#define maxn 500000
int n, q;
int a[256][maxn];
int sum(int x,char c)
{
    int ans=0;
    ans = a[c][n] *( x / n);
    x %= n;
    ans += a[c][x];
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        cin >> n >> q;
        string s;
        cin >> s;
        a[s[0]][1]++;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 'a'; j <= 'z'; j++)
            {
                a[j][i] = a[j][i - 1];
            }
            a[s[i - 1]][i] = a[s[i - 1]][i - 1] + 1;
        }
        for (int i = 1; i <= q; i++)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            int x = l / n + 1, y = r / n;
            int z = y - x;
            char c[5];
            scanf("%s", c);
            printf("%d\n",sum(r,c[0]) - sum(l-1,c[0]));
        }
    }
    return 0;
}
