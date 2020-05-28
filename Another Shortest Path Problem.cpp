#include<bits/stdc++.h>
using namespace std;
#define mst(ss,b) memset((ss),(b),sizeof(ss))
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> PL;
typedef char VertexType;
#define maxnum 100001
typedef struct ArcNode
{
    int adjvex;
    int weight;
    struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode
{
    VertexType data;
    ArcNode *firstarc;
}VNode, AdjList[maxnum];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
}ALGraph;
struct Node
{
    int id;
    int w;
    friend bool operator < (struct Node a, struct Node b)
    {
        return a.w > b.w;
    }
};

int path[maxnum];
int visited[maxnum] = {0};
Node dist[maxnum];
priority_queue<Node>q;
void Dijkstra(ALGraph g, int v0, int n)
{
    for(int i = 1; i <= n; i++)
    {
        dist[i].id = i;
        dist[i].w = INF;
        path[i] = -1;
        visited[i] = 0;
    }
    dist[v0].w = 0;
    q.push(dist[v0]);
    while(!q.empty())
    {
        Node cd = q.top();
        q.pop();
        int u = cd.id;

        if(visited[u])
            continue;
        visited[u] = 1;
        ArcNode *p = g.vertices[u].firstarc;

        while(p)
        {
            int tempv = p->adjvex;
            int tempw = p->weight;

            if(!visited[tempv] && dist[tempv].w > dist[u].w+tempw)
            {
                dist[tempv].w = dist[u].w+tempw;
                path[tempv] = u;
                q.push(dist[tempv]);
            }
            p = p->nextarc;
        }
    }
}

void CreateALGraph(ALGraph &g, int arc, int vex)
{
    g.arcnum = arc;
    g.vexnum = vex;
    int v1, v2, i, w;

	for(i = 1; i <= vex; i++)
	{
		g.vertices[i].firstarc = NULL;
	}
    for(i = 1; i <= arc; i++)
    {
        cin >> v1 >> v2 >> w;
        ArcNode *q = (ArcNode*)malloc(sizeof(ArcNode));
        q->adjvex = v2;
        q->weight = w;
		q->nextarc = g.vertices[v1].firstarc;
		g.vertices[v1].firstarc = q;
    }
}
int DFS(ALGraph g, int i, int j)
{
    visited[i] = 1;
	ArcNode *p = g.vertices[i].firstarc;
	while(p)
	{
		if(p->adjvex == j)
			return 1;
		if(!(visited[p->adjvex]) && DFS(g, p->adjvex, j))
			return 1;
		p = p->nextarc;
	}
	return 0;
}

int BFS(ALGraph g, int i, int j)
{
    queue<int>q;
    q.push(i);
    visited[i] = 1;
    ArcNode *p;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        p = g.vertices[temp].firstarc;

        while(p)
        {
            if(p->adjvex == j)
                return 1;
            if(!(visited[p->adjvex]))
            {
                visited[p->adjvex] = 1;
                q.push(p->adjvex);
            }
            p = p->nextarc;
        }
    }
    return 0;
}
int main()
{
    int m, n;
    cin >> n ;
    m=n;
    ALGraph g;
    CreateALGraph(g, m, n);
    int v0, ve;
    while(cin >> v0 >> ve)
    {
    Dijkstra(g, v0, n);
        cout << dist[ve].w << endl;
    }
    return 0;
}
