#include<bits/stdc++.h>
using namespace std;
long long v[100005];
int main()
{
	int n;
	cin >> n;
	long long sum = 0;
	for(int i = 0; i < n ; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	long long val = *max_element(v,v+n);
	long long x = ((sum + n-2) / (n-1));
	cout << max(val,x) << '\n';
	return 0;
}
