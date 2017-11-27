#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,hit,t;
	cin >> n >> hit >> t;
	
	long long v[n];
	
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v,v+n);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		long long aux = (long long)ceil((double)v[i]/(double)hit);
		if(aux <= t)
			t -= aux;
		else
			break;
		ans++;
	}
	cout << ans << '\n';
	
	return 0;
}
