#include<bits/stdc++.h>
using namespace std;
#define maxn 5000001
#define MAXN 2000001
#define N 1000001
#define ll long long
#define pi 0.57721566490153286060651209
#define mod 1000000007
int father[10010];
void init(int num)
{
    for (int i=0;i<num;++i)
    {
        father[i]=i;
    }
}
int getfather(int i)
{
    if(i==father[i])
    {
        return i;
    }
    else
    {
        father[i] = getfather(father[i]);
        return father[i];
    }
}
void un(int a, int b)
{
    int fa=getfather(a);
    int fb=getfather(b);
    if(fa!=fb)
    {
        if(fa>fb)
        {
            father[fa]=fb;
        }
        else
        {
            father[fb]=fa;
        }
    }
}
int num;
int main()
{
    ios::sync_with_stdio(false);
    cin>>num;
    init(num);
    map<string,vector<int>> m;
    vector<string> user;
    for (int i=0;i<num;++i)
    {
        string name;
        int mailnum;
        cin >> name >> mailnum;
        user.push_back(name);
        for (int j=0;j<mailnum;++j)
        {
            string mail;
            cin >> mail;
            m[mail].push_back(i);
        }
    }
    for (auto it=m.begin();it!=m.end();++it)
    {
        for (int j=1;j<it->second.size();++j)
        {
            un(it->second[0],it->second[j]);
        }
    }
    vector<int> group[10010];
    for(int i=0;i<num;i++)
    {
        if(getfather(i)!=i)
        group[getfather(i)].push_back(i);
    }
    for(int i=0;i<num;i++)
    {
        if(getfather(i)==i)
        {
            cout<< user[i];
            for(int j=0;j<group[i].size();j++)
            {
                cout<<" "<<user[group[i][j]];
            }
            cout<<endl;
        }
    }
    return 0;
}
