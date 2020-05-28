#include<bits/stdc++.h>
using namespace std;
#define N 101
#define ll long long
string a;
int n,k;
int b[256];
char c[400001];
void init(int k)
{
    int j=0;
    for(int i=0;i<256&&k;i++)
    {
       if(k>0)
       {
           if(b[i]>=k)
           {
               b[i]-=k;
               k=0;
           }
           else if(b[i]>0&&b[i]<k)
           {
               k-=b[i];
               b[i]=0;
           }
       }
    }
    for(int i=a.length()-1;i>=0;i--)
    {
        if(b[a[i]]>0)
        {

               c[j]=a[i];
               j++;
               b[a[i]]--;
        }
    }
    c[j]='\0';
     string s=c;
     reverse(s.begin(),s.end());
        cout<<s<<endl;
}
int main()
{
    scanf("%d %d",&n,&k);
        memset(b,0,sizeof(b));
            cin>>a;
        for(int i=0;i<n;i++)
        {
            b[a[i]]++;
        }
    init(k);
    return 0;
}
