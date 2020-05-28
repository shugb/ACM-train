#include<bits/stdc++.h>
using namespace std;
#define maxn 5000001
#define MAXN 2000001
#define N 1000001
#define ll long long
#define pi 0.57721566490153286060651209
double a[N];
int t;
int x,y;
void init()
{
    a[1]=0;
    for(int i=2;i<N;i++)
    {
        a[i]+=a[i-1]+log((double)i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    init();
    scanf("%d",&t);
    int flag=0;
    while(t--)
    {
        scanf("%d%d",&x,&y);
        if(x==0)
           printf("Case %d: 1\n",++flag);
        else
        {
            double ans=a[x]/log((double)y);
            if(ans!=(int)ans)
                ans=(int)ans+1;
            printf("Case %d: %.lf\n",++flag,ans);
        }
    }
    return 0;
}
