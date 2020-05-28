#include<bits/stdc++.h>
using namespace std;
#define mst(ss,b) memset((ss),(b),sizeof(ss))
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> PL;
#define maxn 120005
int N,M;
const int SIZE = 200005;
int c[SIZE];
int A[SIZE];
int Next[SIZE];
int res[100005];
int show[100005];
int hou[SIZE];
bool fir[SIZE];
set<int> u;
struct Q
{
    int l,r;
    int pos;
}q[200005];
int lowbit(int k)
{
    return k&(-k);
}
void modify(int n,int v)
{
    while(n <= N)
    {
        c[n] += v;
        n += lowbit(n);
    }
}
int sum(int n)
{
    int ans = 0;
    while(n > 0)
    {
        ans += c[n];
        n -= lowbit(n);
    }
    return ans;
}
int cmp(Q a, Q b)
{
    return a.l < b.l;
}
int main()
{
    while(scanf("%d %d",&N,&M)==2)
    {
        u.clear();
        memset(A,0,sizeof(A));
        memset(show,0,sizeof(show));
        memset(fir,false,sizeof(fir));
        memset(res,0,sizeof(res));
         memset(Next,0,sizeof(Next));
          memset(c,0,sizeof(c));
          memset(hou,0,sizeof(hou));
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&A[i]);
        A[i+N]=A[i];
    }
    for(int i=N;i>=1;i--)
    {
        u.insert(A[i]);
        hou[i]=u.size();
    }
    N=2*N;
    for(int i=N;i>=1;i--)
    {
        if(!show[A[i]])
        {
            show[A[i]] = i;
            fir[i] = true;
        }
        else
        {
            Next[i] = show[A[i]];
            fir[Next[i]] = false;
            fir[i] = true;
            show[A[i]] = i;
        }
    }
    for(int i=1;i<=M;i++)
    {
        scanf("%d%d",&q[i].l,&q[i].r);
        int v=q[i].l;
        q[i].l=q[i].r;
        q[i].r=v+N/2;
        q[i].pos = i;
    }
    sort(q+1,q+1+M,cmp);
    for(int i=1;i<=N;i++)
        if(fir[i])
        {
            modify(i,1);
        }
    int qtemp = q[1].l;
    int ptr = 1;
    for(int i=1;i<=M;i++)
    {
        for(;ptr<q[i].l;ptr++)
        {
            if(fir[ptr])
            {
                modify(ptr,-1);
                fir[ptr] = false;
                if(Next[ptr])
                {
                    fir[Next[ptr]] = true;
                    modify(Next[ptr],1);
                }
            }
        }
        ptr = q[i].l;
        qtemp = q[i].l;
        if(q[i].l>=q[i].r||(q[i].r-q[i].l==1))
        {
            res[q[i].pos]=u.size();
        }
        else
        {
        if(q[i].l==1&&q[i].r==N/2)
        {
            res[q[i].pos]= A[1]==A[N/2]?1:2;
        }
        else
        {
        res[q[i].pos] =sum(q[i].l+N/2)-sum(q[i].r-1);
        }
        }
    }
    for(int i=1;i<=M;i++)
    {
        printf("%d\n",res[i]);
    }
    }
    return 0;
}
