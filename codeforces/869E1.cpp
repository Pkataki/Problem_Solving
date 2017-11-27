#include <bits/stdc++.h>
using namespace std;
long long bit[3000][3000];
int n,m,q;
map< pair< pair<int,int>, pair<int,int> >, long long > hashes;
void update(int x, int y, long long val)
{
	for(int i = x; i <= n ; i += i & (-i))
		for(int j = y; j <= m ; j += j & (-j))
			bit[i][j] += val;
}
long long query(int x, int y)
{
	long long ans = 0;
	for(int i = x; i > 0 ; i -= i & (-i))
		for(int j = y; j > 0 ; j -= j & (-j))
			ans += bit[i][j];
	
	return ans;
}
long long rd()
{
	return (rand() << 20) + rand();
}
int main()
{
	cin >> n >> m >> q;
	for(int i = 0 ; i < 100; i++)
	{
		srand(rd());
	}
	for(int i = 0; i < q ; i++)
	{
		int op, r1,c1,r2,c2;
		cin >> op >> r1 >> c1 >> r2 >> c2;
		if(op == 1)
		{
			long long h = rd();
			hashes[{ {r1,c1} , {r2,c2}  }] = h;
			update(r1,c1,h);
			update(r1,c2+1,-h);
			update(r2+1,c1,-h);
			update(r2+1,c2+1,h);
		}
		else if(op == 2)
		{
			long long h = hashes[{{r1,c1},{r2,c2}}]; 
			update(r1,c1,-h);
			update(r1,c2+1,h);
			update(r2+1,c1,h);
			update(r2+1,c2+1,-h);
		}
		else
		{
			long long q1 = query(r1,c1);
			long long q2 = query(r2,c2);
			if(q1 == q2)
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
	return 0;
}
