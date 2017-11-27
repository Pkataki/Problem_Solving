#include <bits/stdc++.h>
using namespace std;
int cores[110];
vector<int> grafo[105];
int n;
int k;
vector <int> v_ans(105);
int ans;
bool can(int at)
{
	for(int i = 0; i < grafo[at].size(); i++)
	{
		if(cores[grafo[at][i]])
			return false;
	}
	return true;
}
void solve(int at)
{
	if(at >= n + 1)
	{
		int a = 0;
		vector <int> aux;
		for(int i = 1; i <= n; i++)
		{
			a += cores[i];
			if(cores[i])
				aux.push_back(i);
		}
		if(ans < a)
		{
			ans = a ;
			v_ans = aux;
		}
		return;
	}

	solve(at+1);
	if(can(at))
	{	
		cores[at] = 1;
		solve(at+1);
		cores[at] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	while(test--)
	{
		cin >> n >> k;
		
		for(int i = 1; i <= 102; i++)
			grafo[i].clear();
		
		fill(v_ans.begin(), v_ans.end(), 0);

		memset(cores,0,sizeof(cores));
		
		for(int i = 0; i < k; i++)
		{
			int a,b; cin >> a >> b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
		ans = 0;
		solve(1);
		cout << ans << '\n';
		for(int i = 0; i < ans; i++)
		{
			if( i ) cout << ' ';

			cout << v_ans[i];
		}
		cout << '\n';
	}
}
