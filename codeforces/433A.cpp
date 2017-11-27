#include<bits/stdc++.h>
using namespace std;
int cont[250];
int main()
{
	int n;
	cin >> n;
	int sum = 0;
	int v[n];
	for(int i = 0; i < n ; i++)
	{
		cin >> v[i];
		sum += v[i];
		cont[v[i]]++;
	}
	if(cont[100] & 1)
	{
		cout << "NO\n";
		return 0;
	}
	int val = sum/2;
	int aux = 0;
	for(int i = 0; i <= cont[200]; i++)
	{
		if(200 * i <= val && val - 200 *i <= cont[100] * 100)
		{
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
