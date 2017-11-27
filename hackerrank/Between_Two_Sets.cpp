#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int a[n],b[m];
	vector<int>div;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
	{	
		cin >> b[i];
	}
	for(int i = 1; i <= 100; i++)
	{
		bool ok = 1;
		for(int j = 0; j < m; j++)
		{
			if(b[j] % i != 0)
				ok = 0;
		}
		if(ok)
		{
			div.push_back(i);
		}
	}
	int cont = 0;
	for(int i = 0; i < div.size(); i++)
	{
		bool ok = 1;
		for(int j = 0; j < n; j++)
		{
			if(div[i] % a[j] != 0)
				ok = 0;
		}
		if(ok)
			cont++;
	}
	cout << cont << "\n";
	return 0;
}	
