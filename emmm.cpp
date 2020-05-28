#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
const int maxn=1000+10;
struct Point
{
    int x,y;
    Point(){}
    Point(int x,int y):x(x),y(y){}
}P[maxn];
typedef Point Vector;
Vector operator-(Point A,Point B)
{
    return Vector(A.x-B.x,A.y-B.y);
}
long long Cross(Point A,Point B)
{
    return (long long)A.x*B.y-(long long)A.y*B.x;//严重错误,后面的(long long)忘加了
}
double PolygenArea(Point *p,int n)
{
    double area=0;//错误2,area一定要是double的,如果area为int,那么/2会丢失精度
    for(int i=1;i<n-1;++i)
        area += Cross(p[i]-p[0], p[i+1]-p[0]);//错误1,这里不能加abs求绝对值
    return fabs(area)/2;
}
int gcd(int a,int b)
{
    return b==0? a : gcd(b,a%b);
}
int PointInLine(Point A,Point B)//整点线段AB内部的整点数
{
    int dx=abs(A.x-B.x),dy=abs(A.y-B.y);
    if(dx==0 && dy==0) return 0;
    return gcd(dx,dy)-1;
}
long long PointInPolygen(Point *p,int n)//整点多边形内部的整点数
{
    long long s=PolygenArea(p,n);
    long long b=n;//在多边形边上的整点数目
    for(int i=0;i<=n-1;++i)
        b += PointInLine(p[i],p[(i+1)%n]);
    return s-b/2+1;
}

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;++i) scanf("%d%d",&P[i].x,&P[i].y);
        printf("%lld\n",PointInPolygen(P,n));
    }
    return 0;
}
