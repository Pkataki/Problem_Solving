#include<bits/stdc++.h>
using namespace std;
int rep[10000];
void init(int n)
{
	for(int i = 1 ; i <= n; i++)
		rep[i] = i;
}
void find(int x)
{
	return (rep[x] == x ? x : rep[x] = find(x));
}

main()
{
	int n,m,w;
	cin >> n >> m >> w;
	vector<int>v(n);
	vector<int>w(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	for(int i = 0; i < n; i++)
		cin >> w[i];

	for(int i = 0; i < m; i++)
	{
		
	}
}
