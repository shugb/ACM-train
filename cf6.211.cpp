#include<bits/stdc++.h>
using namespace std;
#define N 101
#define ll long long
int n;
int prime[N],nprime;
bool is[101],isprime[N];
string a;
void doprime()
{
    ll i,j;
    nprime=0;
    memset(isprime,true,sizeof(isprime));
    isprime[1]=0;
    for(i=2;i<N;i++)
    {
        if(isprime[i])
        {
            prime[++nprime]=i;
            for(j=i*i;j<N;j+=i)
                prime[j]=false;
        }
    }
}
bool isp(int n)
{
    int i,k=(int)sqrt(double(n));
    for(i=1;prime[i]<=k;i++)
        if(n%prime[i]==0)
        return 0;
    return 1;
}
void init()
{
    for(int i=1;i<N;i++)
    {
        is[i]=isp(i);
    }
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        cin>>a;
        if(is[a.length()]==1)
        {
            reverse(a.begin(),a.end());
            cout<<a<<endl;
        }
        else
        {
            for(int i=2;i<=a.length();i++)
            {
                if(a.length()%i==0)
                {
                    reverse(a.begin(),a.begin()+i);
                }
            }
            cout<<a<<endl;
        }
    }
    return 0;
}
