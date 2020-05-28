#define LOCAL
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define INF 10000000
#include<cstring>
#include<algorithm>
#include <iomanip>
#define offset 10000
#define eps 1e-5
#define LL long long
using namespace std;
vector<vector<int> > FindThreeElements3(vector<int>& vec, int sum)
{
	vector<vector<int> > result;
	if (vec.size() < 3)
		return result;
	sort(vec.begin(), vec.end());
	for (int a = 0; a < vec.size() - 2; ++a) {
		int b = a + 1, c = vec.size() - 1;
		while (b < c) {
			if (vec[a] + vec[b] + vec[c] < sum)
				++b;
			else if (vec[a] + vec[b] + vec[c] > sum)
				--c;
			else {
				vector<int> temp;
				temp.push_back(vec[a]);
				temp.push_back(vec[b]);
				temp.push_back(vec[c]);
				result.push_back(temp);
				++b;
				--c;
			}
		}
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	return result;
}
void PrintFourElementsResult(vector<vector<int> >& result) {
    if (result.size() == 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // LOCAL
    int n,sum,t;
    while(cin>>n>>sum)
    {
        vector<int> A;
        for(int i=0;i<n;i++)
        {
            cin>>t;
            A.push_back(t);
        }
    vector<vector<int> > result = FindThreeElements3(A,sum);
    PrintFourElementsResult(result);
    }
    return 0;
}
