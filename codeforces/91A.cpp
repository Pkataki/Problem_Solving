#include<bits/stdc++.h>
using namespace std;
int nex[10005][27];
bool vis[30];
int main()
{
	string s,t;
	cin >> s >> t;
	memset(nex,-1,sizeof(nex));
	for(int i = s.size() - 1; i >=  0 ; i--)
	{
		for(int j = 0; j < 26; j++)
		{
			nex[i][j] = nex[i+1][j];
		}
		vis[s[i] - 'a'] = 1;
		nex[i][s[i] - 'a'] = i;
	}	
	int pos = 0;
	int ans = 1;
	for(int i = 0; i < t.size(); i++)
	{
		if(vis[t[i] - 'a'] == 0)
		{
			cout << "-1\n";
			return 0;
		}
		if(nex[pos][t[i] - 'a'] == -1)
		{
				ans++;
				pos = 0;
		}
		if(nex[pos][t[i] - 'a'] == -1)
		{
				
				cout << "-1\n";
				return 0;
		}

		pos = nex[pos][t[i] - 'a'] + 1;
	}
	cout << ans << '\n';

	return 0;
}
