#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int v[n];
	for(int i = 0 ; i < n ; i++)
		cin >> v[i];
	sort(v,v+n);
	int r = n/2;
	int ans = 0;
	for(int l = 0; l < (n/2); l++)
	{
		while(r < n && 2*v[l] > v[r])
			r++;
		if(r == n)
			break;
		r++;
		ans++;
	}
	cout << n - ans << '\n';
	return 0;
}
