#include<bits/stdc++.h>
using namespace std;
set<int>c,a;
int main()
{
	int n,k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		c.insert(i);
		a.insert(i);
	}
	for(int i = 0; i < k; i++)
	{
		int aa;
		cin >> aa;
		c.erase(aa);

	}
	return 0;
}
