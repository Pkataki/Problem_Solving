#include <bits/stdc++.h>
using namespace std;
long long bit[10005];
int maxval;
int update(int idx)
{
	while(idx <= maxval)
	{
		bit[idx] += 1LL;
		idx += idx & (-idx);
	}
}
long long get(int idx)
{
	long long sum = 0;
	while(idx)
	{
		sum += bit[idx];
		idx -= idx & (-idx);
	}
	return sum;
}
int main()
{
	int test;
	cin >> test;
	for(int t = 1; t <= test; t++)
	{
		memset(bit,0,sizeof(bit));
		int n,m,k;
		cin >> n >> m >> k;
		maxval = m;
		vector<pair<int,int> >v(k);
		for(int i = 0 ; i < k ; i++)
		{
			cin >> v[i].first >> v[i].second;
		}
		sort(v.begin(),v.end());
		long long ans = 0;
		for(int i = 0 ; i < k ; i++)
		{
			ans += (get(m) - get(v[i].second));
			update(v[i].second);
		}
		cout <<"Test case " << t << ": " << ans << '\n';
	}
	return 0;
}
