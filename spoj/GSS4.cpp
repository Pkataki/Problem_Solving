#include <bits/stdc++.h>
using namespace std;

long long v[100005];
long long bit[100005];
int rep[100005];

int find(int x)
{
	if(x != rep[x]) rep[x] = find(rep[x]);
	return rep[x];
}

void update(int idx, long long val ,int n)
{
	while(idx <= n)
	{
		bit[idx] += val;
		idx += idx & (-idx);
	}
}
long long query(int idx)
{
	long long sum  = 0;
	while(idx > 0)
	{
		sum += bit[idx];
		idx -= idx & (-idx);
	}
	return sum;
}
void modify(int l, int r, int n)
{
//	int i = find(l);
int i = l;
	while(l <= i && i <= r )
	{
//		if(v[i] != 1)
//		{
			update(i,-v[i],n+2);
			v[i] = (long long)sqrt(v[i]);
			update(i,v[i],n+2);
//			if(v[i] == 1)
//				rep[i] = i+ 1;
//		}
//		i = find(i+1);
	i++;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	int t = 0;
	while(cin >> n)
	{
		t++;
		memset(bit,0,sizeof(bit));
		for(int i = 1 ; i <= n ; i++)
		{
			rep[i] = i;
			cin >> v[i];
			update(i,v[i],n+2);
		
		}
		cout << "Case #" << t << ":\n";
		int q;
		cin >> q;
		while(q--)
		{
			int op, l,r;
			cin >> op >> l >> r;
			if(l > r)
				swap(l,r);
			if(op)
				cout << query(r) - query(l-1) << "\n";
			else
				modify(l,r,n);
		}
		cout << '\n';
	}

	return 0;
}
