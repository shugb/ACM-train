#include<bits/stdc++.h>
using namespace std;
#define maxn 5000001
#define MAXN 2000001
#define N 1000001
#define ll long long
typedef unsigned long long ull;
#define pi 0.57721566490153286060651209
int t;
ull a;
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    int flag=0;
    while(t--)
    {
        cin>>a;
        a=a*(ull)10;
        cout<<"Case "<<++flag<<":";
        for(int i=9;i>=0;i--)
        {
            if((a-i)%9==0)
            {
                cout<<" "<<(a-i)/9;
            }
        }
        cout<<endl;
    }
    return 0;
}
