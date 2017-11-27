#include<bits/stdc++.h>
using namespace std;
int v[300005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	sort(v,v+n);
	long long ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans += (long long)abs(v[i] - (i + 1));	
	}
	cout << ans << '\n';
}
