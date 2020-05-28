#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXV=100000,MAXE=300000;
int inf=100000000;
int head[MAXV],tot;
struct node
{
    int next,c,to;
}E[MAXE];
struct Max_flow
{
    int S,T,n;
    int lev[MAXV],q[MAXV],cur[MAXV],f;
    void init(int _S,int _T)
    {
        tot=0;
        S=_S;T=_T;
        n=T+1;
        for(int i=0;i<=n;i++) head[i]=-1;
    }
    void add(int a,int b,int c)
    {

        E[tot].next=head[a];
        E[tot].to=b;
        E[tot].c=c;
        head[a]=tot++;
    }
    void Add(int a,int b,int c)
    {
        add(a,b,c);
        add(b,a,0);
    }
    int bfs()
    {
        for(int i=0;i<=n;i++) lev[i]=0;
        lev[S]=1;
        f=0;
        q[f++]=S;
        for(int i=0;i<f;i++)
        {
            int u=q[i];
            for(int i=head[u];i!=-1;i=E[i].next)
                if(lev[E[i].to]==0&&E[i].c>0)
                {
                    int to=E[i].to;
                    lev[to]=lev[u]+1;
                    q[f++]=to;
                    if(to==T) return 1;
                }
        }
        return 0;
    }
    int dfs(int u,int f)
    {
        if(u==T) return f;
        int tag=0,c;
        for(int &i=cur[u];i!=-1;i=E[i].next)
        {
            int to=E[i].to;
            if(E[i].c>0&&lev[to]==lev[u]+1)
            {
                c=dfs(to,min(f-tag,E[i].c));
                E[i].c-=c;
                E[i^1].c+=c;
                tag+=c;
                if(tag==f) return  tag;
            }
        }
        return tag;
    }
    int solve()
    {
        int ans=0;
        while(bfs())
        {
            for(int i=0;i<=n;i++) cur[i]=head[i];
            ans+=dfs(S,inf);
        }
        return ans;
    }
}Flow;
int n,F,D,Fi,Di,x,S,T,le,ri;
int work()
{
    Flow.init(S=0,T=2*n+F+D+1);
    for(int i=1;i<=F;i++) Flow.Add(S,i,1);
    for(int i=1;i<=D;i++)  Flow.Add(F+i,T,1);
    for(int i=1;i<=n;i++)
    {
        cin>>Fi>>Di;
        le=F+D+i*2-1;
        ri=le+1;
        Flow.Add(le,ri,1);
        while(Fi--)
        {
            cin>>x;
            Flow.Add(x,le,1);
        }
        while(Di--)
        {
            cin>>x;
            Flow.Add(ri,F+x,1);
        }
    }
    return Flow.solve();
}
int main()
{
    while(cin>>n>>F>>D)
    {
        printf("%d\n",work());
    }
    return 0;
}
