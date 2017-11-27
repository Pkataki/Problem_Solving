#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin >>n>> k;
	int v[n];
	for(int i = 0; i < n; i++)
		cin >> v[i];
	int ans = 0;
	for(int i = 1; i < n; i++)
	{
		ans += max(0,k-v[i]-v[i-1]);
		v[i] += max(0,k-v[i]-v[i-1]);
	}
	cout << ans << '\n';
	for(int i = 0; i < n; i++)
	{
		if(i)
			cout << ' ';
		cout << v[i];
	}
	cout << '\n';
	return 0;
}
