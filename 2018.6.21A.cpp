#include<iostream>
#include<queue>
using namespace std;
#define ll long long
#define eps 1e-7
int ans[510][510];
int n,indegree[510];
void tuopu()
{
	int i,j,t,top;
	queue<int>q;
    for(i=1;i<=n;++i)
    {
    	if(indegree[i]==0)
    	{
    		q.push(i);
    		break;
    	}
    }
    int sign=1;
    while(!q.empty())
    {
    	top=q.front();
    	q.pop();
    	indegree[top]=-1;
    	if(sign)
    	{
    		printf("%d",top);
    		sign=0;
    	}
    	else
		    printf(" %d",top);
		for(i=1;i<=n;++i)
	    {
	    	if(ans[top][i]==1)
	    	   indegree[i]--;
	    }
		for(i=1;i<=n;++i)
		{
			if(indegree[i]==0)
			{
				q.push(i);
				break;
			}
		}
    }
    printf("\n");
}

int main()
{
	int i,m,a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(indegree,0,sizeof(indegree));
		memset(ans,0,sizeof(ans));
		for(i=0;i<m;++i)
		{
			scanf("%d%d",&a,&b);
			if(ans[a][b]==0)
			{
				ans[a][b]=1;
				indegree[b]++;
			}
		}
		tuopu();
	}
	return 0;
}
