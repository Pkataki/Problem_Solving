#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m;
	while(cin >> n >> m && (n || m))
	{
		vector<vector<int> >mat(n,vector<int>(m));
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++)
				cin >> mat[i][j];
		
		int q;
		cin >> q;
		while(q--)
		{
			int l,r;
			cin >> l >> r;
			int ans  = 0;
			for(int i = 0; i < n ; i++)
			{
				vector<int>::iterator it = lower_bound(mat[i].begin(), mat[i].end(), l);
				if(it != mat[i].end())
				{
					int y = it - mat[i].begin();
					int x = i;
					int cont = 0;
					while(x < n && y < m && mat[x][y] <= r)
					{
						x++;
						y++;
						cont++;
					}
					ans = max(ans,cont);
				}
			}
			cout << ans << '\n';
		}
		cout << "-\n";

	}
	return 0;
}
