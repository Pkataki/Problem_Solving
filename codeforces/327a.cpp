#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a;
	int ans = -1, total = 0, now = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		if(a)
			now--,total++;
		else
			now++;
		if(now > ans)
			ans = now;
		if(now < 0)
			now = 0;
	
	}
	cout << ans + total << '\n';
	return 0;
}
