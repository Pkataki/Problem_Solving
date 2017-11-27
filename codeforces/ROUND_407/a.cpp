#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin >> n >> k;
	int v[n];
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v,v+n,greater<int>());
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if(v[i] >= k)
		{
			ans += ceil((double)(v[i])/(double)k);
		}
		else
			ans++;
	}
	cout << ceil((double)(ans+1))/2 << '\n';
		
}
