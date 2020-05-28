#include<bits/stdc++.h>
using namespace std;
#define maxn 5000001
#define MAXN 11000
#define ll long long
#define N 5000001
#define INF 0x7fffffff
#define mem(x) memset(x,0,sizeof(x))
#define PI acos(-1)
#define eps 1e-10
using namespace std;
int ans[MAXN];
int cnt[MAXN];
int len;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}
ll powmod(ll a,ll b,ll MOD)
{
    ll ans=1;
    while(b)
   {
            if(b%2)
            ans=ans*a%MOD;a=a*a%MOD;b/=2;
   }
   return ans;
}
void mul(int x)
{
	int c=0;
	for(int i=0;i<len;i++)
	{
		int k=ans[i]*x+c;
		c=k/10;
		ans[i]=k%10;
		if(i==len-1&&c)
		{
			len++;
		}
	}
}

int main()
{
     ios::sync_with_stdio(false);
     int t,n,i,j,a;
    int cas=0;
    cin>>t;
    while(t--)
    {
    	mem(cnt);mem(ans);
    	cin>>n;
    	for(i=0;i<n;i++)
    	{
    		cin>>a;
    		int x=a;
    		for(j=2;j<=a;j++)
    		{
    			int ccnt=0;
    			if(x%j==0)
    			{
    				while(x%j==0)
    				{
    					ccnt++;
    					x/=j;
					}
				}
				cnt[j]=max(cnt[j],ccnt);
				if(x==1)
				break;
			}
		}
		ans[0]=1;len=1;
		for(i=2;i<10010;i++)
		{
			if(cnt[i])
			{
				int num=(int)pow(i,cnt[i]);
				mul(num);
			}
		}
		printf("Case %d: ",++cas);
		for(j=len-1;j>=0;j--)
		printf("%d",ans[j]);
		printf("\n");
    }
     return 0;
}
