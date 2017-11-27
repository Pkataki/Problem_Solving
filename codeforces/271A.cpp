#include<bits/stdc++.h>
using namespace std;
int p[105];
int get(int x)
{
	if(x == p[x])
		return x;
	return p[x] = get(p[x]);
}
int x[105];
int y[105];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		p[i] = i;
	}
	for(int i = 0; i < n-1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(x[i] == x[j] || y[i] == y[j])
				p[get(i)] = get(j);
		}
	}
	int ans= 0;
	for(int i = 0; i < n; i++)
	{
		if(p[i] == i)
			ans++;
	}
	cout << ans-1 << '\n';
}
