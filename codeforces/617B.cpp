#include<bits/stdc++.h>
using namespace std;
int main()
{
	int prev = -1;
	long long ans = 0;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if(a)
		{
			if(prev == -1)
				ans = 1;
			else
				ans *= (i - prev);
			prev = i;
		}
	}
	cout << ans << '\n';
	return 0;
}
