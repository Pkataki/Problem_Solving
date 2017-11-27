#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[2][2001][11];
vector<pair< ll,int> >v(2000);
long long primes[] = {29,23,19,17,13,11,7,5,3,2,1};
int n,w;
void solve(int pos, int p, int peso)
{
	p = min(p, 10);
	if(pos == n || peso == 0)
	{
		dp[pos][p][peso] = 0;
		return;
	}
	if(dp[pos][p][peso] != -1LL)
		return;
	
	ll ans = 0LL;

	solve(pos+1,p, peso);
	ans = dp[pos+1][p][peso];

	if(peso - v[pos].second >= 0)
	{
		solve(pos+1,p+1,peso - v[pos].second);
		ans = max(ans,dp[pos+1][min(p+1,10)][peso - v[pos].second] + v[pos].first*primes[p]);
	}
	
	dp[pos][p][peso] = ans;
}

main()
{
	memset(dp,0,sizeof(dp));
	cin >> n >> w;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(),v.end(),greater<pair<ll,int> >());
	//solve(0,0,w);
	dp[0][0][0] = 0;
	int cur = 0;
	for(int i = 0; i <= n; i++)
	{
		cur = 1-cur;
		for(int peso = 0; peso <= w; peso++)
		{
			for(int p = 0; i < 11; i++)
			{
				dp[cur][peso][p] = dp[1-cur][peso][p];
				if(peso - v[i].second >= 0)
				{
					dp[cur][peso][p] = max(dp[1-cur][peso-v[i].first][max(p-1,0)] + v[i].first,dp[cur][peso][p]);
				}
			}
		}
	}
	cout << dp[cur][0][w] << '\n';
	

	/*
	solve1(0,w);
	
	sort(ans.begin(),ans.end(),greater<ll>());
	ll ans1 = 0LL;
	for(int i = 0; i < ans.size(); i++)
	{
		ans1 += (i <= 9 ? (ans[i]*primes[i]) : (ans[i]));
	}
	cout << ans1 << "\n";
	*/
}
