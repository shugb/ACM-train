#include<bits/stdc++.h>
using namespace std;
#define maxn 5000001
#define MAXN 2000001
#define N 1000001
#define ll long long
#define pi 0.57721566490153286060651209
#define mod 1000000007
double dp[105][605];
int n,m;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        memset(dp,0,sizeof(dp));
	for(int i=1;i<=6;i++)
	{
    	dp[1][i]=(1.0/6);
	}

	for(int i=2;i<=n;i++)
	{
    	for (int j=i;j<=m;j++)
   	  {
        if(j-i<6)
		{
            for(int k=i-1;k<j;k++)
			{
                dp[i][j]+=dp[i-1][k]/6;

            }
        }
        else
		{
            for(int k=j-6;k<j;k++)
			{
                dp[i][j]+=dp[i-1][k]/6;
            }
        }
      }
	}
	printf("%.2lf\n",dp[n][m]*100);
    }
	return 0;
}
