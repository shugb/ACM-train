#include<bits/stdc++.h>
using namespace std;
#define maxn 7010
#define maxm 100010
struct Matrix
{
    int m[105][105];
    int N,M;
};
Matrix A,B;
int C[105*105];
void multi(Matrix a,Matrix b)
{
    memset(C,0,sizeof(C));
    int k=0,o=0;
     for(int p=1;p<=(a.N-b.N+1)*(a.M-b.M+1);p++)
        {
    for(int i=0;i<b.N;i++)
    {
           for(int j=0;j<b.M;j++)
        {
            C[p]+=a.m[i+k][j+o]*b.m[i][j];
        }
    }
    if(b.M+o==a.M)
    {
        o=0;
        k++;
            cout<<C[p]<<endl;
    }
    else
     {
       o++;
       cout<<C[p]<<" ";
     }
        }
}
int main()
{
    int n,m,h,w;
    while(cin>>n>>m)
    {
       A.N=n;
       A.M=m;
       for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
          cin>>A.m[i][j];
       cin>>h>>w;
       B.N=h;
       B.M=w;
     for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
          cin>>B.m[i][j];
    multi(A,B);
    }
    return 0;
}
