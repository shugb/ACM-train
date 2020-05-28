#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
#define ll long long
#define eps 1e-7
struct TPoint
{
  ll x;
  ll y;
};
TPoint a[4];
struct TCircle
{
    ll r;
    TPoint centre;
};
struct TTriangle
{
    TPoint t[3];
};
ll triangleArea(TTriangle t)
{
    return abs(t.t[0].x*t.t[1].y+t.t[1].x*t.t[2].y+t.t[2].x*t.t[0].y-t.t[1].x*t.t[0].y-t.t[2].x*t.t[1].y-t.t[0].x*t.t[2].y)/2;
}
ll Distance(TPoint p1,TPoint p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
TCircle of(TTriangle t)
{
    TCircle tmp;
    ll a,b,c,c1,c2;
    ll xa,ya,xb,yb,xc,yc;
    a=Distance(t.t[0],t.t[1]);
    b=Distance(t.t[1],t.t[2]);
    c=Distance(t.t[2],t.t[0]);
    tmp.r=a*b*c/triangleArea(t)/4;
    xa=t.t[0].x;ya=t.t[0].y;
    xb=t.t[1].x;yb=t.t[1].y;
    xc=t.t[2].x;yc=t.t[2].y;
    c1=(xa*xa+ya*ya-xb*xb-yb*yb)/2;
    c2=(xa*xa+ya*ya-xc*xc-yc*yc)/2;
    tmp.centre.x=(c1*(ya-yc)-c2*(ya-yb))/((xa-xb)*(ya-yc)-(xa-xc)*(ya-yb));
    tmp.centre.y=(c1*(xa-xc)-c2*(xa-xb))/((ya-yb)*(xa-xc)-(ya-yc)*(xa-xb));
    return tmp;
}
int t;
void run()
{
    TTriangle ce;
    for(int i=0;i<3;i++)
    {
        ce.t[i].x=a[i].x;
        ce.t[i].y=a[i].y;
    }
    TCircle m=of(ce);
    if(m.r>=Distance(m.centre,a[3]))
    {
        cout<<"Rejected"<<endl;
    }
    else
    {
        cout<<"Accepted"<<endl;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<4;i++)
        {
            scanf("%lld %lld",&a[i].x,&a[i].y);
        }
        run();
    }
    return 0;
}

