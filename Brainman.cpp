#define LOCAL
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define INF 10000000
#include<cstring>
#include<algorithm>
#include <iomanip>
#define offset 10000
#define eps 1e-5
#define LL long long
#define Max 1000001
using namespace std;
int n,a[Max],temp[Max];
int ans;
void Sort(int i, int j)
{
    if(i==j)
        return ;
    int mid=(i+j)/2;
    Sort(i,mid);
    Sort(mid+1,j);
    int l,r,k;
    for(l=i,r=mid+1,k=i;k<=j;k++)
    {
        if(l>mid)
        {
            temp[k]=a[r];
            r++;
        }
        else if(r>j)
        {
            temp[k]=a[l];
            l++;
        }
        else if(a[l]<=a[r])
        {
            temp[k]=a[l];
            l++;
        }
        else
        {
            temp[k]=a[r];
            r++;
            ans+=mid-l+1;
        }
    }
    for(k=i;k<=j;k++)
    {
        a[k]=temp[k];
    }
}
int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // LOCAL
    int t,flag=0;
    cin>>t;
    while(t--)
    {
      ans=0;
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=0;i<n;i++)
          {

            cin>>a[i];
          }
        Sort(0,n-1);
         cout<<"Scenario #"<<++flag<<":"<<endl<<ans<<endl;
    }
    return 0;
}
