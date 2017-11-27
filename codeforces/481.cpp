#include<bits/stdc++.h>
using namespace std;
int bit[100005];
int ask(int idx)
{
	int ans = 0;
	while(idx)
	{
		ans= max(bit[idx],ans);
		idx -= idx & -idx;
	}
	return ans;
}
void update(int idx, int val)
{
	while(idx <= 100000)
	{
		bit[idx] = max(val,bit[idx]);
		idx += idx & -idx;
	}
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		update(a , ask(a) + 1);
	}
	cout << ask(n) << '\n';
	return 0;
}
