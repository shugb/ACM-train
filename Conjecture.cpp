#include<bits/stdc++.h>
using namespace std;
#define maxn 5000001
#define MAXN 2000001
#define N 10000001
#define ll long long
#define pi 0.57721566490153286060651209
int t,a,cnt;
bool v[N]={0};
int prime[666666];
void doprime()
{
   cnt=0;
    v[1]=1;
    for(int i=2; i<=10000000; i++)
    {
        if(!v[i])
        {
            prime[cnt++]=i;
            for(int j=i+i; j<=10000000; j+=i)
                v[j]=1;
        }
    }
}
int solve(int a)
{
    int ans=0;
    for(int i=0;i<cnt;i++)
    {
        if(prime[i]>=a/2+1)
        {
                break;
        }
       if(!v[a-prime[i]]&&a>=prime[i]*2)
        ans++;
    }
    return ans;
}
int main()
{
     ios::sync_with_stdio(false);
     doprime();
     cin>>t;
     int flag=0;
     while(t--)
     {
         cin>>a;
          printf("Case %d: %d\n",++flag,solve(a));
     }
     return 0;
}
