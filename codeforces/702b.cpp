#include<bits/stdc++.h>
using namespace std;
int v[100005];
int lis[100005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int ma = 1;
	int ans = 1;
	for(int i = 1; i < n; i++)
	{
		if(v[i] > v[i-1])
		{
			ma++;		
		}
		else
		{
			ans = max(ma,ans);
			ma = 1;
		}
	}
	ans = max(ans,ma);
	cout << ans << '\n';
	return 0;
}
