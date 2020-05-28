#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define INF 10000000000
#include<cstring>
#include<algorithm>
#include <iomanip>
using namespace std;
typedef long long LL;
LL a[222222];
int t;
const int N=2;
struct Matrix
{
    LL v[N][N];
};
Matrix A=
{
    1,1,
    1,0
};
Matrix I=
{
    1,0,
    1,0
};

Matrix matrix_mul(Matrix A, Matrix B)
{
    Matrix ans;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans.v[i][j] = 0;
            for (int k = 0; k < N; k ++)
            {
                ans.v[i][j] += (A.v[i][k] * B.v[k][j]) ;
            }
        }
    }
    return ans;
}
Matrix matrix_pow(Matrix C, long long n)
{
    Matrix ans = {1, 0, 0, 1};
    while (n)
    {
        if (n & 1)
            ans = matrix_mul(ans, C);
        C = matrix_mul(C, C);
        n >>= 1;
    }
    return ans;
}
int main()
{
    LL n,s;
    int i;
    a[0]=0;
    a[1]=1;
    for(i=2;i<10000;i++)
    {
         Matrix res = matrix_pow(A, i - 2);
        res = matrix_mul(res, I);
        a[i]=res.v[0][0] ;
    }
    scanf("%d",&t);
    while(t--)
    {
        s=0;
        scanf("%lld",&n);
        if(n<8)
            cout<<2<<endl;
        else
        {
            for(int i=0;a[i]<=n;i++)
            {
                if(a[i]%2==0)
                    s+=a[i];
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
