#include<bits/stdc++.h>
using namespace std;
map<int,int>mapa;
int v[200005];
long long ans = 0;
long long sum = 0;

int main()
{
	int n,m;
	cin >> n;
	for(int i = 0 ; i < n; i++)
	{
		cin >> v[i];
	}
	sum = v[0];
	mapa[v[0]]++;
	long long a,b,c;
	for(int i = 1; i < n ; i++)
	{
		if(mapa.count(v[i]))
			a = mapa[v[i]];
		else
			a = 0;
		if(mapa.count(v[i]-1))
			b = mapa[v[i]-1];
		else
			b = 0;
		if(mapa.count(v[i]+1))
			c = mapa[v[i]+1];
		else 
			c = 0;
		ans += -sum + (a*v[i] + b*(v[i]-1) + c*(v[i]+1) );
		ans += v[i]*(i - a - b - c);
		mapa[v[i]]++;
		sum += v[i];
	}
	cout << ans << '\n';
	return 0;
}
