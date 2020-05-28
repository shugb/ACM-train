#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<string,int> p;
int n,s;
string a;
int main()
{
    scanf("%d",&n);
    s=0;
    for(int i=0;i<n;i++)
     {
        cin>>a;
        p[a]++;
     }
    for(int i=0;i<n;i++)
     {
        cin>>a;
        p[a]--;
     }
     for(map<string,int>::iterator iter=p.begin();iter!=p.end();iter++)
     {
        if(iter->second>=1)
            s+=iter->second;
     }
     cout<<s<<endl;
    return 0;
}
