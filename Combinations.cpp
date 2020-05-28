#include<bits/stdc++.h>
using namespace std;
#define maxn 5000001
#define MAXN 2000001
#define N 1000001
#define ll long long
#define pi 0.57721566490153286060651209
#define mod 1000003
ll mub[1000003];
ll x, y ;
void init()
{
    mub[0] = 1;
    for(int i=1; i<=1000002; i++)
    {
        mub[i] = mub[i-1] * i % mod;
    }
}
ll work( ll m , ll n )
{
    if(m == n) return 1;
    if(n == 1) return m;
    else return (work( m-1, n-1 ) + work( m-1, n )) % mod;
}

inline ll extend_gcd(ll a, ll b, ll &x, ll &y)
{
    if(a == 0 && b == 0)
        return -1;
    if(b == 0){
        x = 1; y = 0;
        return a;
    }
    ll d = extend_gcd(b, a % b, y, x);
        y -= a / b * x;
    return d;
}

inline ll mod_reverse(ll a, ll n)
{
   ll d = extend_gcd(a, n, x, y);
    if(d == 1)
        return ( x % n + n ) % n;
    else
        return -1;
}

ll solve(ll a, ll b){
    if(a > b) return 0;
    ll nn = mod_reverse((mub[a] * mub[(b + mod - a) % mod]) % mod, mod);
    return mub[b] * nn % mod;
}

void to_solve(ll a, ll b)
{
    if(b < mod){
        solve(a, b);
        return;
    }
    cout << solve(a/mod, b/mod) * solve(a%mod, b%mod) << endl;
}
int t;
ll a,b;
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    init();
    int flag=0;
    while(t--)
    {
        cin>>a>>b;
        if(b<1000003)
            cout<<"Case "<<++flag<<": "<<solve(b,a)<<endl;
        else
       {
            cout<<"Case "<<++flag<<": ";
            to_solve(b,a);
            cout<<endl;
       }
    }
    return 0;
}
