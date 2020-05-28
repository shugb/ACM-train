#include <iostream>
using namespace std;
int a[200005];
int main ()
{
    int n;
    while(cin>>n)
    {
        for (int i=0;i<=n;i++)
            cin>>a[i];
        long long s=0;
        for (int i=n;i>=0;i--)
        {
            s+=a[i];
            if(s>=i)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
