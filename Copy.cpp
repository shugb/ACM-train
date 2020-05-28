#include<iostream>
#include<cstdio>
using namespace std;
const long long M = 1e9+7;
const long long MAXL = 1000000;
int main()
{
    int n;
    long long a,sum;
    while(scanf("%d",&n)==1)
    {
        sum=1;
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&a);
            sum=sum*(1+a)%M;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
