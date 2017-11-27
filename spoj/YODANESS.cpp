#include <bits/stdc++.h>
using namespace std;
int bit[300005];
void update(int idx)
{
	while(idx <= 300005)
	{
		bit[idx]++;
		idx += idx & (-idx);
	}
}
int get(int idx)
{
	int sum = 0;
	while(idx)
	{
		sum += bit[idx];
		idx -= idx & (-idx);
	}
	return sum;
}
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		memset(bit,0,sizeof(bit));
		int n;
		cin >> n;
		int v[n];
		map<string,int>mapa;
		for(int i = 0 ; i < n ; i++)
		{
			string s;
			cin >> s;
			mapa[s] = i+2;
		}
		for(int i = 0 ; i < n ; i++)
		{
			string s;
			cin >> s;
			v[i] = mapa[s];
		}
		int ans = 0;
		for(int i = n-1; i>= 0; i--)
		{
			ans += get(v[i]-1);
			update(v[i]);
		}
		cout << ans << '\n'; 
	}
	return 0;
}
