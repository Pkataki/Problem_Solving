#include<bits/stdc++.h>
using namespace std;
int p[2005];
int dist[2005];
int solve(int x)
{
	if(dist[x] != 0)
		return dist[x];
	if(p[x] == -1)
		return dist[x] = 1;
	return dist[x] = solve(p[x])+1;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&p[i]);
		if(p[i] != -1)
			p[i]--;
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans = max(ans,solve(i));
	
	printf("%d\n",ans);
}
