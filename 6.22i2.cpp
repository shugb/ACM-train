#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 100
#define rep(i, n) for (int i = 0; i <= (n); i++)
#define repf(i, s, n) for (int i = (s); i <= (n); i++)

const int MAXN = 110;
int m[MAXN][MAXN], s[MAXN][MAXN], a[MAXN], n;

void maxSeq(int* a, int len, int &res) {
    res = a[0];
    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (sum < 0)
            sum = a[i];
        else sum += a[i];
        if (res < sum)
            res = sum;
    }
}

int main() {
    scanf("%d", &n);
    repf(i, 1, n) repf(j, 1, n) {
        scanf("%d", &m[i][j]);
        s[i][j] = s[i - 1][j] + m[i][j];
    }
    int ans = -0xfffffff, res;
    repf(i, 0, n - 1) repf(j, i + 1, n) {
        repf(k, 1, n) a[k] = s[j][k]- s[i][k];
        maxSeq(a + 1, n, res);
        ans = max(ans, res);
    }
    printf("%d\n", ans);
    return 0;
}
