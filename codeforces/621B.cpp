#include <bits/stdc++.h>
using namespace std;

int n,a[100100],b[100100];

int main() 
{
	cin >> n;
	for(int i = 0;i < n; i++)
	{
		int x,y;
		cin >> x >> y;
		a[x+y]++;
		b[x-y+10000]++;
	}
	long long res=0;
	for(int i = 0;i <= 30000; i++) 
		res+=(1ll*a[i]*(a[i]-1)/2)+(1ll*b[i]*(b[i]-1)/2);
	cout<<res << '\n';

	return 0;
}
