#include<bits/stdc++.h>
using namespace std;
int bit[30005];
int n;
void update(int idx, int val)
{
	while(idx <= n)
	{
		bit[idx] += val;
		idx += idx & (-idx);
	}
}
int query(int idx)
{
	int sum = 0;
	while(idx)
	{
		sum += bit[idx];
		idx -= idx & (-idx);
	}
	return sum;
}
int v[30005];
int main()
{
	for(int t = 1; t<= 10 ; t++)
	{
		string s;
		cin >> n;
		getchar();
		cin >> s;
		for(int i = 1 ; i <= n ; i++)
		{
			v[i] = (s[i-1] == '(' ? 1 : -1);
			update(i,v[i]);
			update(i+1,-v[i]);
		}
				for(int i = 1; i <= n ; i++)
					cout << query(i) << ' ';
				cout << '\n';
		int q;
		cin >> q;
		cout << "Test " << t << ":\n";
		while(q--)
		{
			int a;
			cin >> a;
			if(a)
			{
				update(a+1,-v[a]);
				v[a] = -v[a];
				update(a,v[a]);
				update(a+1,-v[a]);
			}
			else
			{
				cout << (query(n) == 0 ? "YES\n" : "NO\n");
			}

		}
		memset(bit,0,sizeof(bit));
	}
	return 0;
}
