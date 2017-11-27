#include<bits/stdc++.h>
using namespace std;
long long adj[65];
int ans,best;
int n,m;
void solve(int i, long long mask , int depth)
{
	if(mask == (1LL << n)-1)
	{
		ans++;
		best = max(best,depth);
	}
	else
	{
		for(int j = i; j < n; j++)
		{
			if(!(mask & (1LL << j)))
				solve(j+1,adj[j] | mask,depth+1);
		}
	}
}
main()
{
	ios_base::sync_with_stdio(false);
	int test;
	//scanf("%d",&test);
	cin >> test;
	while(test--)
	{
		cin >> n >> m;
		//scanf("%d%d",&n,&m);
		for(int i = 0; i <= n; i++)
			adj[i] = (1LL << i);
		for(int i = 0; i < m; i++)
		{
			int a,b;
			//scanf("%d%d",&a,&b);
			cin >> a >> b;
			adj[a] |= (1LL << b);
			adj[b] |= (1LL << a);
		}
		best = ans = 0;
		solve(0,0LL,0);
		//printf("%d\n%d\n",ans,best);
		cout << ans << "\n" << best << "\n";
	}
}
