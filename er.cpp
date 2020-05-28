
#include<iostream>
#include<cstdio>
#include<cmath>
#define INF 10000000000
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include <iomanip>
#define offset 10000
#define eps 1e-5
#define LL long long
const int MAX_V = 1000;
using namespace std;
int V,E;

vector<int> G[MAX_V];
int color[MAX_V];
bool dfs(int v,int c)
{
    color[v] = c;

    for (int i = 0; i < G[v].size(); i++)
    {
        if (color[G[v][i]] == c)
            return false;
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c))
            return false;
    }

    return true;
}

void solve()
{
    for (int i = 0; i < V; i++)
    {
        if (color[i] == 0)
        {
            if (!dfs(i, 1))
            {
                printf("No\n");
                return;
            }
        }
    }

    printf("Yes\n");
}

int main()
{
    while(cin >> V >> E)
    {
        memset(color,0,sizeof(color));
        memset(G,0,sizeof(G));
    for (int i = 0; i < E; i++)
    {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    solve();
    }
    return 0;
}
