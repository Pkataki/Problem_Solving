#include<bits/stdc++.h>
using namespace std;
int sum[100005];
int main()
{
	int n;
	long long k;
	cin >> n >> k;
	long long v[n+1];
	memset(v,-1LL,sizeof(v));
	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	sort(v,v+n+1);
	long long ans;
	long long ma = -1;
	for(int i = 1; i <= n; i++)
	{
		sum[i] = sum[i-1] + v[i];
		long long l = 1;
		long long r = i;
		while(l != r)
		{
			long long mid = (l+r) >> 1;
			long long aux = v[i]*(i-mid+1)  - (sum[i] - sum[mid-1]);
			if(aux <= k)
				r = mid;
			else
				l = mid + 1;
		}
		if((i-l+1) > ma)
		{
			ma = i-l+1;
			ans = v[i];
		}
	}
	cout << ma << ' ' << ans << '\n';
}
