#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m,k,a,b,c;
    int t;
    ll ans1=0,ans2=0,ans3=0;
    cin>>t;
    while(t--)
    {
        ans1=0;
        ans2=0;
        ans3=0;
        cin>>n>>m>>k>>a>>b>>c;
        ans1+=min(((ll)ceil(n/2)+(ll)ceil(m/2)+k)*a,((ll)ceil((n+k)/3)+(ll)ceil((m+k)/3))*b);
        ans2+=k*c+min(((ll)ceil(n/2)+(ll)ceil(m/2))*a,((ll)ceil(n/3)+(ll)ceil(m/3))*b);
        ans3+=
        cout<<min(ans1,ans2,ans3)<<endl;
    }
    return 0;
}
