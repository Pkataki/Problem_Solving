#include<bits/stdc++.h>
using namespace std;
int v[100005];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	int ans = 0;
	while(m--)
	{	
		int a,b;
		cin >> a >> b;
		ans += min(v[a],v[b]);
	}
	cout << ans << '\n';
}
