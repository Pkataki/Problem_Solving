#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin >> n >> k;
	if(n == 1)
	{
		if(k == 0)
			cout << "1\n";
		else
			cout << "-1\n";
		return 0;
	}
	if(k < n/2)
	{
		cout << "-1\n";
		return 0;
	}

	int x = k - (n/2) + 1;	
	cout << x << ' ' << 2*x;
	
	for(int i = 1; i <= n-2; i++ )
		cout << ' ' << 2*x+i;
	cout << endl;
	return 0;
}
