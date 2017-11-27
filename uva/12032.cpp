#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int test;
	cin >> test;
	for(int c = 1; c <= test; c++)
	{
		int n;
		cin >> n;
		vector<int>v(n+1);
		v[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(),v.end());
		int lo = 0;
		int hi = 10000000;
		while(lo < hi)
		{
			int mid = (lo+hi) >> 1;
			int aux = mid;
			bool ok = 1;
			for(int i = 0; i+1<= n && ok; i++)
			{
				if(v[i+1]-v[i] == aux)
					aux--;
				else if(v[i+1]-v[i] > aux)
					ok = 0;
			}
			if(!ok)
				lo = mid+1;
			else
				hi = mid;	
		}
		cout << "Case " << c << ": " << lo << "\n";
	}
	return 0;
}
