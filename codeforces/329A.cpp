#include <bits/stdc++.h>
using namespace std;
string mat[105];
map<int,int>mapa;
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> mat[i];
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n ; j++)
		{
			if(mat[i][j] == '.')
				mapa[i] = j;
		}
	}
	if((int)mapa.size() == n)
	{
		for(auto it = mapa.begin(); it != mapa.end(); it++)
		{
			cout << it->first + 1 <<" " << it->second+1 << '\n';
		}
		return 0;
	}
	mapa.clear();
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n ; j++)
		{
			if(mat[j][i] == '.')
				mapa[i] = j;
		}
	}
	if((int) mapa.size() == n)
	{
		for(auto it = mapa.begin(); it != mapa.end(); it++)
		{
			cout << it->second + 1 <<" " << it->first+1 << '\n';
		}
		return 0;
	}
	cout << "-1\n";
	return 0;
}
