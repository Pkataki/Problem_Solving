#include<bits/stdc++.h>
using namespace std;
long long p[100];
long long v[10];
long long ans[10];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	long long val = 0;
	for(int i = 0; i < 5; i++)
		cin >> v[i];

	for(int i = 0; i < n; i++)
	{
		val += p[i];
		for(int j = 4; j >= 0; j--)
		{
			if(val < v[j])
				continue;
			long long a = val/v[j];
			ans[j] += a;
			val -= a * v[j];
		}
	}
	for(int i = 0 ; i < 5; i++)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n' << val << '\n';
	return 0;
}
