#include<bits/stdc++.h>
using namespace std;
int lis[2005],lds[2005], v[2005];
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		for(int i = n-1; i >= 0; i--)
		{
			lis[i] = lds[i] = 1;
			for(int j = n-1; j > i; j--)
			{
				if(v[j] < v[i])
				{
					lis[i] = max(lis[i],lis[j]+1);
				}
				else
				{
					lds[i] = max(lds[i],lds[j]+1);
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			ans = max(ans,lis[i] + lds[i] - 1);
		}
		cout << ans << '\n';
	}
	return 0;
}
