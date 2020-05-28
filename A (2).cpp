#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool panduan(string t)
{
    if(t.length()%4!=0)
        return false;
    else
    {
        for(int i=3;i<t.length();i+=4)
        {
            if(t[i]=='0'&&t[i-1]=='5'&&t[i-2]=='0'&&t[i-3]=='2')
                continue;
            else
                return  false;
        }
    }
    return true;
}
int main()
{
    string m;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>m;
        if(panduan(m))
        {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
    return 0;
}
