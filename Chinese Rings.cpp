#include<bits/stdc++.h>
#define INF 10000000000
using namespace std;
typedef long long LL;
const int MOD=200907;
const int N=3;
struct Matrix
{
    LL v[N][N];
};
Matrix A=
{
    1,2,1,
    1,0,0,
    0,0,1
};

Matrix I=
{
    1,0,0,
    0,0,0,
    1,0,0
};

Matrix matrix_mul(Matrix A, Matrix B, long long m)
{
    Matrix ans;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans.v[i][j] = 0;
            for (int k = 0; k < N; k ++)
            {
                ans.v[i][j] += (A.v[i][k] * B.v[k][j]) % m;
            }
            ans.v[i][j] %= m;
        }
    }
    return ans;
}
Matrix matrix_pow(Matrix C, long long n, long long m)
{
    Matrix ans = {1, 0, 0,
                  0, 1, 0,
                  0, 0, 1
                  };
    while (n)
    {
        if (n & 1)
            ans = matrix_mul(ans, C, m);
        C = matrix_mul(C, C, m);
        n >>= 1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    LL n;
    while(cin>>n&&n)
    {
        if (n==1)
        {
            cout << 1 << endl;
            continue;
        }
        if(n==0)
         {
        cout<<0<<endl;
         }
        else{
         Matrix res = matrix_pow(A, n - 1, MOD);
        res = matrix_mul(res, I, MOD);
        cout << res.v[0][0] << endl;
        }
    }
    return 0;
}
