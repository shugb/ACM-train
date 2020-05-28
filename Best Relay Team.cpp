#include<bits/stdc++.h>
using namespace std;
#define mst(ss,b) memset((ss),(b),sizeof(ss))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> PL;
#define maxn 120005
struct sports
{
    string name;
    double x,y;
};
sports men1[501];
sports men2[501];
int n;
struct s
{
    double fen;
    string f1;
    string f[3];
};
s s1[250001];
bool cmp1(sports a,sports b)
{
    if(a.x!=b.x)
    return a.x<b.x;
    else
     return a.y>b.y;
}
bool cmp2(sports a,sports b)
{
    if(a.y!=b.y)
    return a.y<b.y;
    else
    return a.x>b.x;
}
bool cmp3(s a,s b)
{
    return a.fen<b.fen;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>men1[i].name>>men1[i].x>>men1[i].y;
        men2[i].name=men1[i].name;
        men2[i].x=men1[i].x;
        men2[i].y=men1[i].y;
    }
    sort(men2,men2+n,cmp2);
    sort(men1,men1+n,cmp1);
   for(int i=0;i<n;i++)
  {
      s1[i].fen=men1[i].x;
      s1[i].f1=men1[i].name;
    for(int j=0,flag=0;j<n&&flag<3;j++)
   {
       if(men1[i].name!=men2[j].name)
       {
           s1[i].fen+=men2[j].y;
           s1[i].f[flag]=men2[j].name;
           flag++;
       }
   }
  }
   sort(s1,s1+n,cmp3);
      cout << fixed << setprecision(9)<<s1[0].fen<<endl;
      cout<<s1[0].f1<<endl;
      for(int i=0;i<3;i++)
      {
          cout<<s1[0].f[i]<<endl;
      }
    return 0;
}
