#include<bits/stdc++.h>
using namespace std;
int color[100005];
set<int>v[100005];
bool vis[100005];
bool exist[100005];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&color[i]);
		exist[color[i]] = 1;
	}
	while(m--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(color[a] != color[b])
		{
			v[color[a]].insert(color[b]);
			v[color[b]].insert(color[a]);
		}
	}
	int ans;
	int ma = 0;
	for(int i = 0; i < 100001; i++)
	{
		if(ma < v[i].size())
		{
			ans = i;
			ma = v[i].size();
		}
	}
	for(int i = 0; i < 100001; i++)
	{
		if(exist[i] && ma == v[i].size())
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}
