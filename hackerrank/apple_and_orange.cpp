#include<bits/stdc++.h>
using namespace std;
int main()
{
	int s,t,a,b;
	int m,n;
	cin >> s >> t;
	cin >> a >> b;
	cin >> m >> n;
	vector<int> apple(m);
	vector<int> orange(n);
	for(int i = 0; i < m; i++)
		cin >> apple[i];
	
	for(int i = 0; i < n; i++)
		cin >> orange[i];

	int conta = 0;
	for(int i = 0; i < m; i++)
	{
		if(a+apple[i] >= s && a+apple[i] <= t)
			conta++;
	}
	int conto = 0;
	for(int i = 0; i < n; i++)
	{
		if(b+orange[i] >= s && b+orange[i] <= t)
			conto++;
	}
	cout << conta << "\n" << conto << "\n";
	return 0;
}
