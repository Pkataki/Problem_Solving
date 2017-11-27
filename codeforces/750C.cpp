#include<bits/stdc++.h>
using namespace std;
pair<int,int>v[200004];
int n;
int check(int rating)
{
	int div = v[0].second;
	for(int i = 0 ; i < n ; i++)
	{
		if(rating < 1900 && v[i].second != 2)
			return 0;
		if(rating >= 1900 && v[i].second != 1)
			return -1;
		rating += v[i].first;
	}
	return 1;
}
int main()
{
	cin >> n;
	int sum = 0;
	for(int i = 0 ; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
		sum += v[i].first;
	}
	int lo = -200000000;
	int hi = 200000000;
	int ans = -200000000;
	while(lo <= hi)
	{
		int mid = (lo+hi) >> 1;
		if(check(mid) == 1)
		{
			ans = max(ans,mid);
			lo = mid+1;
		}
		else if(check(mid) == 0)
			lo = mid+1;
		else
			hi = mid-1;
	}
	if(ans == -200000000)
		cout << "Impossible\n";
	else if(ans == 200000000)
		cout << "Infinity\n";
	else
		cout << ans+sum << '\n';
	return 0;
}
