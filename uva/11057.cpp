#include<bits/stdc++.h>
using namespace std;
vector<int>v(10005);
inline int bs(int x, int lo, int hi)
{
	while(lo <= hi)
	{
		int mid = (lo+hi)/2;
		if(v[mid] == x)
			return mid;
		if(x < v[mid])
			hi = mid-1;
		else 
			lo = mid+1;
	}
	return -1;
}
main()
{
	int n;
	while(cin >> n)
	{
		v = vector<int>(n);
		for(int i = 0; i < n; i++)
			cin >> v[i];
		int val;
		cin >> val;
		sort(v.begin(),v.end());
		int r  = 0;
		int l = (1 << 30);
		for(int i = 0; i < n; i++)
		{
			int search = abs(val-v[i]);
			int idx = bs(search,i,n-1);
			if(idx != -1)
			{
				if(abs(v[i]-v[idx]) < abs(l-r) && v[i]+v[idx] == val)
				{
					l = min(v[i],v[idx]);
					r = max(v[i],v[idx]);
				}
			}
		}
		cout << "Peter should buy books whose prices are " << l << " and " << r << ".\n\n";
	}
}
