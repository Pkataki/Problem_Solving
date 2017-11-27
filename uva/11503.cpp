#include<iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <map>
using namespace std;
int rep[200005];
int r[200005];
int conta[200005];
map<string,int>mapa;
void init(int n)
{
	for(int i = 1; i <= 2*n; i++)
	{
		rep[i] = i;
		conta[i] = 1;
		r[i] = 0;
	}
}
int find(int x)
{
	return (rep[x] == x) ? x : rep[x] = find(rep[x]);
}
void unio(int x, int y)
{
	int px = find(x);
	int py = find(y);
	if(find(x) == find(y))
		return;

	if(r[px] > r[py])
	{
		conta[find(px)] += conta[find(py)];
		rep[py] = px;
	}
	else 
	{
		conta[find(py)] += conta[find(px)];
		rep[px] = py;
		if(r[px] == r[py])
			r[py]++;
	}
}
main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int cont = 1;
		init(n);
		mapa.clear();
		while(n--)
		{
			string a,b;
			cin >> a >> b;
			if(!mapa.count(a))
			{
				mapa[a] = cont;
				cont++;
			}
			if(!mapa.count(b))
			{
				mapa[b] = cont;
				cont++;
			}
			unio(mapa[a],mapa[b]);
			cout << conta[find(mapa[a])] << '\n';
		}
	}
}
