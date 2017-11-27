#include <bits/stdc++.h>
using namespace std;
int v[100005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n ; i++)
		cin >> v[i];
	int ans = 2;
	int cnt = 2;
	for(int i =2; i < n ; i++)
	{
		cnt++;
		if(v[i] != v[i-1]+v[i-2])
			cnt = 2;

		ans =max(ans,cnt);
	}
	cout << min(ans,n) << '\n';
	return 0;
}
