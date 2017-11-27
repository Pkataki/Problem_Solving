#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
pair<ull,ull> dp[16][16][(1 << 16)+1];
int n;
ull altura[16];
pair<ull,ull> solve(int pos, int ant ,int state)
{
	if(__builtin_popcount(state) == n)
	{
		return make_pair(altura[pos],1);
	}
	if(dp[pos][ant][state] != pair<ull,ull>(-1,-1))
	{
		return dp[pos][ant][state];
	}	
	ull qt = 0ULL;
	pair<ull,ull> aux;
	pair<ull,ull> ans;
	ans.first = 0ULL;
	aux.first = 0ULL;
	ans.second = 0ULL;
	aux.second = 0ULL;
	for(int i = 1; i <= n; i++)
	{
		if(!(state & (1ULL << i)))
		{
			aux = solve(i, pos, (state|(1ULL << i)));
			
			aux.first += (abs(altura[pos]-altura[ant]) + 2ULL);				
		}
		if(aux.first > ans.first)
		{	
			ans = aux;
		}
		else if(aux.first == ans.first)
		{
			ans.second += aux.second;
		}
	}
	return dp[pos][ant][state] = ans;
}
main()
{
	while(cin >> n && n)
	{
		for(int i = 0; i < 16; i++)
			for(int j = 0; j < 16; j++)
				for(int k = 0; k <= (1 << 16); k++)
					dp[i][j][k] = make_pair(-1,-1);
		
		for(int i = 1; i <= n; i++)
			cin >> altura[i];
		
		altura[0] = 0;
		pair<ull,ull>ans = solve(1,0,0);
		cout << ans.first << " " << ans.second << "\n";
	}
}
