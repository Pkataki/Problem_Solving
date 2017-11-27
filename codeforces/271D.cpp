#include<bits/stdc++.h>
using namespace std;
struct node
{
	int nxt[26];
}tree[2250000];
string s,d;
int k;
int ans;
int n_nodes;
void dfs(int no, int val)
{
	if(val <= k)
		ans++;
	for(int i = 0; i < 26; i++)
	{
		if(tree[no].nxt[i])
			dfs(tree[no].nxt[i], val + (d[i] == '0'));
	}
}
int main()
{
	cin >> s >> d >> k;
	for(int i = 0; i < s.size(); i++)
	{
		int cur = 0;
		for(int j = i; j < s.size(); j++)
		{
			if(!tree[cur].nxt[s[j] - 'a'])	
			{
				tree[cur].nxt[s[j] - 'a'] = ++n_nodes;
			}
			cur = tree[cur].nxt[s[j] - 'a'];
		}
	}
	dfs(0,0);
	ans--;
	cout << ans << '\n';
}
