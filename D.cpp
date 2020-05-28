#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include <iomanip>
#include<vector>
#define offset 10000
#define eps 1e-5
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 200005;
int n,Q,nxt[N][26],t[N];
char s[N],ope[10],c;
int main()
{
    scanf("%s %d",s+1,&Q);
    n=strlen(s+1);
    memset(nxt[n],-1,sizeof(nxt[n]));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<26;j++)
        {
            if(s[i+1]-'a'==j)nxt[i][j]=i+1;
            else nxt[i][j] = nxt[i+1][j];
        }
    }
    int len=1;
    t[0]=0;
    while(Q--)
    {
        scanf(" %s",ope);
        if(ope[2]=='s')
        {
            scanf(" %c",&c);
            if(t[len-1]==-1)t[len]=-1;
            else t[len]=nxt[t[len-1]][c-'a'];
            len++;
        }
        else len--;
        if(t[len-1]!=-1)puts("YES");
        else puts("NO");
    }
    return 0;
}
