#include<bits/stdc++.h>
using namespace std;
int v[100005];
int n;
int dp[100005];
int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n ; i++)
		cin >> v[i];
	
	int ans = 1;
	
	for(int i = 0; i < n ; i++)
	{
		vector<int>factors;
		for(int j = 2; j * j <= v[i]; j++)
		{
			if(v[i] % j)
				continue;
			while(v[i] % j == 0)
				v[i] /= j;
			factors.push_back(j);
		}
		
		if(v[i] > 1)
			factors.push_back(v[i]);
		
		int ma = 0;
		
		for(int j = 0; j < factors.size(); j++)
			ma = max(ma,dp[factors[j]]);
		
		ma++;
		
		for(int j = 0; j < factors.size() ; j++)
		{
			dp[factors[j]] = ma;
		}
	}
	
	cout << max(1,*max_element(dp,dp+100005)) << '\n';
	return 0;
}
