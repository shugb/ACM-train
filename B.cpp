#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool panduan(string t)
{
    if(t[0]=='2'&&t[1]=='0'&&t[2]<='4')
        return true;
    else
        return false;
}
int main()
{
    int t;
    ll ans1,ans2;
    string a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        ans1=b[7]-'0'+(b[6]-'0')*10+(b[4]-'0'+(b[3]-'0')*10)*60+(b[1]-'0'+(b[0]-'0')*10)*60*60;
        ans2='0'-b[7]+('6'-b[6])*10+('9'-b[4]+('5'-b[3])*10)*60+('3'-b[1]+('2'-b[0])*10)*60*60;
        ans1%=100;
        ans2%=100;
        if(panduan(a))
        {
            cout<<ans2<<endl;
        }
        else
        cout<<ans1<<endl;
    }
    return 0;
}
