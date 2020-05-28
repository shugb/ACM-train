#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include <iomanip>
using namespace std;
#define ll long long
struct node
{
    int id;
    ll a,b,c;
};
node w[1005];
bool cmp(node x,node y)
{
    return (x.a+x.b)*y.c<(y.a+y.b)*x.c;
}
int t;
int main()
{
    while(cin>>t)
    {
        for (int i=0;i<t;i++)
        {
            cin>>w[i].a>>w[i].b>>w[i].c;
            w[i].id=i+1;
        }
        stable_sort(w,w+t,cmp);
        for (int i=0;i<t;i++)
            i==t-1?cout<<w[i].id<<endl:cout<<w[i].id<<" ";
    }
    return 0;
}
