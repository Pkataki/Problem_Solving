#include<bits/stdc++.h>
using namespace std;
int main()
{
	int v[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int a[50];
	int n;
	cin >> n;
	for(int i = 0; i < n ; i++)
	{
		cin >> a[i];
	}
	bool ok = 0;
	for(int i = 0; i < 12; i++)
	{
		int f = 0;
		for(int j = 0; j < n ; j++)
		{
			if((a[j] == 28 || a[j] == 29) && (v[(i+j) %12] == 28 || v[(i+j)%12] == 29))
				f++;
			else if(a[j] == v[(i+j)%12])
				f++;
		}
		if(f == n)
			ok = 1;
	}
	if(ok)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
