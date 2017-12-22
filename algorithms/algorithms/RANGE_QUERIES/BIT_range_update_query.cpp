#include<bits/stdc++.h>
using namespace std;
int n;
long long bit1[1000000];
long long bit2[1000000];
void update(long long bit[], int idx, long long v)
{
	while(idx <= n)
	{
		bit[idx] += v;
		idx += idx & (-idx);	
	}
}
long long query(long long bit[], int idx)
{
	long long sum = 0;
	while(idx)
	{
		sum += idx;
		idx -= idx & (-idx);
	}
	return sum;
}
void update_range(long long v, int l, int r)
{
	update(bit1, l, v);
	update(bit1, r+1, -v);
	update(bit2, l, v * (l-1));
	update(bit2, r+1, -v * r);
}
long long query_range(int l, int r)
{
	long long q1 =  query(bit1,r) * r - query(bit2, r) ;
	long long q2 =  query(bit1, (l-1) ) * (l- 1) - query(bit2, (l - 1)) ;
	return q1 - q2;
}
main()
{
	int m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int op;
		cin >> op;
		if(!op)
		{
			int l,r;
			long long val;
			cin >> l >> r >>val;
			update_range(val,l,r);
			cout << "BIT 1 - ";
			for(int i = 1; i <= n; i++)
			{
				cout << bit1[i] << ' ';
			}
			cout << "\n";
			cout << "BIT 2 - ";
			for(int i = 1; i <= n; i++)
			{
				cout << bit2[i] << ' ';
			}
			cout << "\n";
		}
		else
		{
			int l,r;
			cin >> l >> r;
			cout << query_range(l,r) << "\n";
		}
	}
}
