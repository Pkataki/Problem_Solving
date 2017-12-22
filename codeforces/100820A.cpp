#include<bits/stdc++.h>
using namespace std;
int d[505][505];
int d1[505][505];
int v[505];
int s[505],t[505],f[505];
int vis[505];
int vi;
int n,m;
int match[1005];
bool bmp(int u)
{
	vis[u] = vi;
	for(int i = 0; i < m ; i++)
	{
		if( (d1[s[u]][f[u]] + v[f[u]] + d[f[u]][s[i]] <= (t[i] - t[u]) )  && (match[i] == -1 || (vis[match[i]] != vi  && bmp(match[i]))))
		{	
			match[i] = u;
			return true;
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	for(int i= 0 ; i < n ; i++)
	{
		for(int j = 0; j < n ; j++)
		{
			cin >> d1[i][j];
			int aux = v[j];
			if(i == j)	
				aux = 0;
			d[i][j] = d1[i][j] + aux;
		}
	}
	for(int k = 0; k < n; k++)
	{
		for(int i = 0; i < n ; i++)
		{
			for(int j = 0; j < n ; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for(int i = 0; i < m; i++)
	{
		cin >> s[i] >> f[i] >> t[i];
		s[i]--;
		f[i]--;
		match[i] = -1;
		vis[i] = 0;
	}
	int ans = 0;
	for(int i = 0; i < m; i++)
	{
		++vi;
		if(bmp(i))
			ans++;
	}
	cout << m-ans << '\n';
	return 0;
}
