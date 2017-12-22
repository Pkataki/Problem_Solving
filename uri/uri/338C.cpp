#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n,m;
		cin >> n >> m;
		int sum = 0;
		int ans = 1;
		for(int i= 0; i < n ; i++)
		{
			
			int a;
			cin >> a;
			if(sum + a <= m)
			{
				sum += a;
			}
			else
			{
				ans++;
				sum = a;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
