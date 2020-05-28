#define LOCAL
#include<iostream>
#include<cstdio>
#include<cmath>
#define INF 10000000000
#include<cstring>
#include<algorithm>
#include <iomanip>
#define offset 10000
#define eps 1e-5
#define LL long long
using namespace std;
int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // LOCAL
    LL n,m,p;
    while(cin>>n>>m)
    {
        cin>>p;
        LL t;
        t=(2-p)*n+(p-1)*m;
        cout<<t<<endl;
    }
    return 0;
}
