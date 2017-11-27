#include<bits/stdc++.h>
using namespace std;
map<string,int>mapa;
int pai[200500];
int n,m,q;
int find(int x)
{
	if(pai[x] != x)
		 pai[x] = find(pai[x]);
	return pai[x];	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> q;
	string s,t;
	for(int i = 0; i < n; i++)
	{	
		cin >> s;
		mapa[s] = i;
		pai[i] = i;
		pai[i+ n] = i + n;
		
	}
	for(int i = 0; i < m; i++)
	{
		int a;
		cin >> a >> s >> t;

		int x = mapa[s];
		int y = mapa[t];

		if(a == 1)
		{
			if(find(x) == find(y + n))
			{
				cout << "NO\n";
				continue;
			}
			cout << "YES\n";
			pai[find(x)] = find(y);
			pai[find(x + n)] = find(y + n);
		}
		else
		{
			if(find(x) == find(y))
			{
				cout << "NO\n";
				continue;
			}
			cout << "YES\n";
			pai[find(x)] = find(y + n);
			pai[find(x + n)] = find(y);	
		}
	}
	while(q--)
	{
		cin >> s >> t;
		int x = mapa[s];
		int y = mapa[t];

		if(find(x) == find(y))
			cout << "1\n";
		else if(find(x) == find(y + n))
			cout << "2\n";
		else
			cout << "3\n";
	}
	return 0;
}
