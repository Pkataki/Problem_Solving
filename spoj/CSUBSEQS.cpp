#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
map<pair<int,pair<int,pair<int, pair<int,char> > > >,long long >dp;
vector<string> s(4);
int pos[4][55][26];
//int dp[52][52][52][52];
int p[4][52];
int sz[4];
long long solve(int p1, int p2, int p3, int p4, char eita)
{
	if(pos[0][p1][eita] < 0 || pos[1][p2][eita] < 0 || pos[2][p3][eita] < 0 || pos[3][p4][eita] < 0)
	{
		return 0;
	}
	p1 = pos[0][p1][eita];
	p2 = pos[1][p2][eita];
	p3 = pos[2][p3][eita];
	p4 = pos[3][p4][eita];
	if ( dp.count({p1,{p2,{p3,{p4,eita}}}}) ) 
		return dp[{p1,{p2,{p3,{p4,eita}}}}];

	long long ans = 1LL;
	for(int ch = 0 ; ch < 26; ch++)
	{
		ans += solve(p1+1,p2+1, p3+1, p4+1, ch); 
	}
	return dp[{p1,{p2,{p3,{p4,eita}}}}] = ans;
}

int main()
{

	for(int i = 0; i < 4; i++){
		getline(cin, s[i]);
		sz[i] = s[i].size();
	}
	
	memset(pos, -1, sizeof(pos));
 
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < sz[i]; j++)
		{
			for(int k = 0; k < 26; k++)
			{
				for(int u = j; u < sz[i]; u++)
				{
					if(s[i][u] - 'a' == k){
						pos[i][j][k] = u;
						break;
					}
				}
			}
		}
	}

	int sz = s[0].size();
	long long ans = 0;
	for(int ch = 0; ch < 26; ch++ )
	{
		ans += solve(0,0,0,0,ch); 
	}
	cout << ans << '\n';
}
