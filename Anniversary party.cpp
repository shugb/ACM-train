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
#define Maxn 500000
const int maxn=6005;
vector<int>son[maxn];
bool vis[maxn];
int dp[maxn][2];
int n;
void dfs(int root)
{
    vis[root]=1;
    for(int i=0;i<son[root].size();i++)
    {
        int v=son[root][i];
        if(!vis[v])
        {
            dfs(v);
            dp[root][1]+=dp[v][0];
            dp[root][0]+=max(dp[v][0],dp[v][1]);
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<=n;i++)
            son[i].clear();
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&dp[i][1]);
            dp[i][0]=0;
        }
        int fa,so;
        while(scanf("%d%d",&so,&fa)!=EOF)
        {
            if(so==0&&fa==0)
                break;
            son[fa].push_back(so);
            son[so].push_back(fa);
        }
        dfs(1);
        cout<<max(dp[1][0],dp[1][1])<<endl;
    }
    return 0;
}
