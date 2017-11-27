#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int ans = 0;
	
	while(n > 0 && m > 0)
	{
		ans++;
		
		if(n < m)
			swap(n,m);

		n -= 2;
		m++;
		if(n < 0 || m < 0)
		{
			ans--;
			break;
		}
	}
	cout << ans << '\n';
}
