#include <bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin >>test;
	vector<int>v;
	for(int i = 100; i< 1000; i++)
	{
		for(int j = 100; j < 1000; j++)
		{
			int aux = i*j;
			if(int(log10(aux) + 1) == 6)
			{
				int aux1 = aux;
				string s = "";
				while(aux1)
				{
					s += char((aux1 % 10)) + '0';
					aux1 /= 10;
				}
				if(s[0] == s[5] && s[1] == s[4] && s[2] == s[3])
					v.push_back(aux);
			}
		}
	}
	sort(v.begin(),v.end());
	while(test--)
	{
		int n;
		cin >> n;
		int ans = 0;
		for(int i = 0; i < v.size(); i++)
		{
			if(v[i] > n)
				break;
			ans = v[i];
		}
		cout << ans << '\n';
	}
	return 0;
}

