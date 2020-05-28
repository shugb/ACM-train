#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
const int MAXN = 100000005;
typedef long long LL;
ll biao[] = { 0,1,2,9,(1 << 18) };
ll phi(ll n)
{
	ll ans = n;
	for (ll i = 2; i*i <= n; i++)
    {
		if (n%i == 0)
		{
			ans -= ans / i;
			while (n%i == 0) n /= i;
		}
	}
	if (n>1) ans -= ans / n;
	return ans;
}
ll mod_pow(ll a, ll n, ll mod){
	a %= mod;
	ll ret = 1;
	while (n){
		if (n & 1) ret = (ret*a)%mod;
		a = a*a%mod;
		n >>= 1;
	}
	return ret;
}
LL f(ll n,ll p)
{
        if(p == 1) return 1;
        if (n <= 4)
	{
		if (biao[n] >= p) return biao[n] % p + p;
		return biao[n];
	}
        ll phip = f(n-1,phi(p));
        return mod_pow(n, phip, p) + p;
}
int main()
{
    ll p;
    ll n;
       while(scanf("%lld %lld",&n, &p)==2)
      {
            ll exp = f(n-1, phi(p));
		    ll ans = mod_pow(n, exp, p);
            printf("%lld\n", ans);
      }
    return 0;
}
