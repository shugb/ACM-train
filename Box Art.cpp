#define LOCAL
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define INF 10000000
#include<cstring>
#include<algorithm>
#include <iomanip>
#define offset 10000
#define eps 1e-5
#define ll long long
#define Max 1000001
using namespace std;
int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // LOCAL
    int t,flag=0,a,p,ans;
    cin>>t;
    while(t--)
    {
        cin>>a>>p;
    if(a<0)
      {
        a=abs(a);
        ans= cal(a,p);
        ans=ans*pow(-1,(p-1)/2);
         cout<<"Scenario #"<<++flag<<":"<<endl<<ans<<endl<<endl;
      }
       else
       {
          ans= cal(a,p);
        cout<<"Scenario #"<<++flag<<":"<<endl<<ans<<endl<<endl;
       }
    }
    return 0;
}
