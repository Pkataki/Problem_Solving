#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
#define ini first.first
#define dur first.second
#define price second
pair<pii,int> v[10010];
int dp[10010];
int n;
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> v[i].ini >> v[i].dur >> v[i].price;

		sort(v,v+n);

		dp[n] = 0;
		for(int i = n-1; i >= 0; i--)
		{
			dp[i] = max(dp[i+1], dp[lower_bound(v,v+n,make_pair(make_pair(v[i].ini + v[i].dur,0),0)) - v] + v[i].price);
		}
		cout << dp[0] << '\n';


	}
}
