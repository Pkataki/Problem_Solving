#include<bits/stdc++.h>
using namespace std;
string v[105];
vector<int> graph[30];
stack<int>ans;
int pre[100];
int vis[100];
int dfs(int x)
{
	if(!vis[x])
	{
		vis[x] = 1;
		pre[x] = 1;
		for(int i = 0; i < graph[x].size(); i++)
		{
			if(!vis[graph[x][i]] && dfs(graph[x][i]))
				return 1;
			else if(pre[graph[x][i]])
				return 1;
		}
	}
	pre[x] = 0;
	return 0;
}
void dfs2(int x)
{
	vis[x] = 1;
	for(int i = 0; i < graph[x].size(); i++)
	{
		if(!vis[graph[x][i]])
		{
			dfs2(graph[x][i]);
		}
	}
	ans.push(x);
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for(int i = 0 ; i < n-1; i++)
	{
		for(int k = i+1; k < n; k++)
		{
			string s1 = v[i];
			string s2 = v[k];
			int j;
			j = 0;
			while(j < s1.size() && j < s2.size() && s1[j] == s2[j])
				j++;
			if(s2[j] == 0)
			{
				puts("Impossible");
				return 0;
			}
			else if(s1[j] == 0)
			{
				continue;
			}
			else if(j < s1.size() && j < s2.size())
			{
				graph[s1[j] - 'a'].push_back(s2[j] - 'a');
			}
		}
	}
	for(int i = 0; i < 26; i++)
	{
		memset(vis,0,sizeof(vis));
		memset(pre,0,sizeof(pre));
		if(dfs(i))
		{
			puts("Impossible");
			return 0;
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i = 0; i < 26; i++)
	{
		if(!vis[i])
			dfs2(i);
	}
	while(ans.size())
	{
		cout << (char)(ans.top() + 'a');
		ans.pop();
	}
	cout << '\n';
}
