//#define LOCAL
#include<iostream>
#include<cstdio>
#include<cmath>
#define INF 10000000000
#include<cstring>
#include<algorithm>
#include<algorithm>
#include <iomanip>
#define offset 10000
#define eps 1e-5
#define LL long long
using namespace std;
int count(int n)
{
    int s=1;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
    {
        int a=0;
        do
        {
            n/=i;
            a++;
        }while(n%i==0);
        s=s*(a+1);
    }
    if(n>1)s=s*2;
    return s;
}
int sum(int n)
{
    int s=1;
    for(int i=2;i*i<=n;i++)
         if(n%i==0)
    {
        int a=1;
        do
        {
            n/=i;
            a*=i;
        }while(n%i==0);
        s=s*(a*i-1)/(i-1);
    }
    if(n>1)s=s*(1+n);
    return s;
}
int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // LOCAL
    int t,a;
    cin>>t;
    while(t--)
    {
        cin>>a;
        cout<<sum(a)-a<<endl;
    }
    return 0;
}
