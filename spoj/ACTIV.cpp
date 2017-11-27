#include<bits/stdc++.h>
using namespace std;
int n;
long long dp[100005];
vector<pair<int,int> > v;
vector<int> v1;
long long solve(int i)
{
	if(i == n)
		return 0LL;
	if(~dp[i])
		return dp[i];
	dp[i] = 0LL;	
	auto it = lower_bound(v1.begin()+i,v1.end(),v[i].second);
	if(it == v1.end())
	{
		dp[i] = 1 + solve(i+1);
	}
	else
	{
		int idx = it - v1.begin();
	//	cout << idx << " **\n";
		dp[i] = (solve(i+1)) + (1 + solve(idx));
	}
	return dp[i]%100000000LL;
}
int main()
{
	ios_base::sync_with_stdio(0);	
	while(cin >> n)
	{
		if(n == -1)
			break;
		for(int i = 0; i < n; i++)
		{
			dp[i] = -1;		
			int a,b;
			cin >>a >> b;
			v.push_back(make_pair(a,b));
			v1.push_back(a);
		}
		sort(v.begin(),v.end());
		sort(v1.begin(),v1.end());
		long long ans = solve(0);
		cout << setfill('0') << setw(8) << ans << '\n';
		//cout << solve(0) << '\n';
		v.clear();
		v1.clear();
	}
	return 0;
}
