#include<bits/stdc++.h>
using namespace std;
int d[100001];
int s[100001];
int D[1000001];
int main()
{
   int t;
   int a,sum;
   cin>>t;
   while(t--)
   {
       sum=0;
       memset(d,0,sizeof(d));
        memset(s,0,sizeof(s));
         memset(D,0,sizeof(D));
       cin>>a;
       for(int i=0;i<a;i++)
       {
           scanf("%d",&d[i]);
       }
       for(int i=0;i<a;i++)
       {
           scanf("%d",&s[i]);
       }
       for(int i=0;i<a;i++)
       {
           D[d[i]-s[i]+200001]++;
       }
       sum=*max_element(D,D+200001);
      cout<<sum<<endl;
   }
   return 0;
}
