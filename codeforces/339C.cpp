#include<bits/stdc++.h>
using namespace std;
int dp[15][15][1005];
string s = "";
int solve(int diff, int last, int qt)
{
	if(qt == 0)
		return 1;
	if(dp[diff][last][qt] != -1)
		return dp[diff][last][qt];
	int aux = 0;
	for(int i = 1; i <= 10; i++)
	{
		if(i != last && i > diff && s[i] == '1')
			aux = max(aux,solve(i-diff,i,qt-1));
	}
	return dp[diff][last][qt] = aux;
}
vector<int> ans;
void print(int diff, int last, int qt)
{
	if(qt == 0)
		return;
	int idx = -1;
	for(int i = 1; i <= 10; i++)
	{
		if(i != last && i > diff && s[i] == '1')
			if(solve(i-diff,i,qt-1))
			{
				idx = i;
				break;
			}
	}
	ans.push_back(idx);
	print(idx-diff,idx,qt-1);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	int n;
	cin >> s >> n;
	s = " " + s;
	int ok = solve(0,0,n);
	if(!ok)
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
		print(0,0,n);
		cout << ans[0];
		for(int i = 1; i < ans.size(); i++)
		{
			cout <<' ' <<  ans[i]; 
		}
		cout << '\n';
	}
	return 0;
}
