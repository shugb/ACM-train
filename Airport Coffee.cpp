#include<bits/stdc++.h>
using namespace std;
#define mst(ss,b) memset((ss),(b),sizeof(ss))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> PL;
const int inf=0x3f3f3f3f;
#define maxn 12005
int n,m;
int w[maxn][maxn];
int path[maxn][maxn];
string s[maxn];
void init()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            w[i][j]=inf;
            path[i][j]=j;
        }
    }
}
void Floyd()
{
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        if(w[i][k]!=inf&&w[k][j]!=inf)
        {
            int temp=w[i][k]+w[k][j];
            if(w[i][j]>temp)
            {
                w[i][j]=temp;
                path[i][j]=path[i][k];
            }
        }
}
void input()
{
    cin>>n;
    init();
    map<string,int> ma;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        ma[s[i]]=i;
    }
    string name1,name2,imp;
    int k;
    for(int i=1;i<=n;i++)
    {
        cin>>name1>>k;
        for(int i=0;i<k;i++)
        {
            cin>>imp;
            getline(cin,name2);
            string temp;
            int j=1;
            for(int i=1;i<name2.length();i++)
            {
                if(name2[i]==',')
                {
                    temp=name2.substr(j,i-j);
                    j=i+2;
                    i++;
                    int u=ma[name1],v=ma[temp];
                    w[u][v]=1;
                }
                else if(i==name2.length()-1)
                {
                    temp=name2.substr(j,i-j+1);
                    int u=ma[name1],v=ma[temp];
                    w[u][v]=1;
                }
            }
        }
    }
}
void print()
{
    int mind=inf;
    int sta,en;
    for(int i=1;i<=n;i++)
    {
        if(w[i][i]<mind)
            sta=en=i,mind=w[i][i];
    }
    if(mind!=inf)
    {
        cout<<s[sta];
        int u=path[sta][en];
        while(u!=en)
        {
            cout<<" "<<s[u];
            u=path[u][en];
        }
        cout<<endl;
    }
    else
        cout<<"SHIP IT"<<endl;
}
int main()
{
    input();
    Floyd();
    print();
    return 0;
}
