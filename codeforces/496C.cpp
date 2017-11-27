#include<bits/stdc++.h>
using namespace std;
char mat[1005][1005];
bool good[1005];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> mat[i][j];
	
	int ans= 0;
	for(int j = 0; j < m; j++)
	{
		bool remove = 0;
		for(int i = 0; i < n; i++)
		{
			if(i+1 < n && mat[i][j] > mat[i+1][j] && !good[i])
				remove = 1;
		}
		ans += remove;
		if(remove)
			continue;
		for(int i = 0; i < n; i++)
		{
			if(i+1 < n && mat[i][j] < mat[i+1][j] && !good[i])
				good[i] = 1;
		}
	}
	cout << ans << '\n';

	return 0;
}
