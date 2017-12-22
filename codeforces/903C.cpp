#include<bits/stdc++.h>
using namespace std;
int v[5005];
bool vis[5005];

map<int,int>mapa;
#define MAXN 50011

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		mapa[v[i]]++;
	}
	auto it = mapa.begin();
	int ans = 0;
	for(;it != mapa.end(); it++)
	{
		ans = max(it->second,ans);
	}
	cout << ans << '\n';
	return 0;
}
