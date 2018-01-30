#include<bits/stdc++.h>
using namespace std;
int v[2005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> v[i];
	}
	int ans = 0;
	for(int i = 0; i < n ; i++)
	{
		for(int j  = i + 1; j < n ; j++)
		{
			if(v[i] > v[j])
				ans++;
		}
	}
	int m;
	cin >> m;
	while(m--)
	{
		int l,r;
		cin >> l >> r;
		int aux = (r - l);
		
		ans += (aux * (aux+1))/2;
		if(ans & 1)
			cout << "odd\n";
		else
			cout << "even\n";
	}
	return 0;
}
