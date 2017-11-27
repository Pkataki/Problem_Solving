#include<bits/stdc++.h>
using namespace std;
string v[200000];
int main()
{
	map<string,bool>mapa;
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> v[i];
	for(int i = n-1 ; i >= 0 ; i--)
	{
		if(mapa.count(v[i]) == 0)
			cout << v[i] << '\n';
		mapa[v[i]] = 1;
	}
	return 0;
}
