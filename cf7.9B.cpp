#include<bits/stdc++.h>
using namespace std;
#define mst(ss,b) memset((ss),(b),sizeof(ss))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> PL;
#define maxn 1000000+5
string a,b;
int t,sum;
int main()
{
    cin>>a>>b;
    sum=0;
    if(a[a.length()-1]!=b[b.length()-1])
    {
        cout<<a.length()+b.length()<<endl;
    }
    else
  {
     for(int i=a.length()-1,j=b.length()-1;i>=0&&j>=0;i--,j--)
    {
        if(a[i]==b[j])
            sum++;
        else
            break;
    }
    cout<<a.length()+b.length()-sum*2<<endl;
  }
  return 0;
}
