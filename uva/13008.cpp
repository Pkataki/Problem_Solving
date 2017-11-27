#include<bits/stdc++.h>
using namespace std;
int d,p,r,b;	
vector<int>rivals[2004];
int dsp[105];
int ppp[105];
int dp[101][1005];
int solve_dsp(int pos, int w)
{
	if(pos > p)
	{
		return 0;
	}
	if(dp[pos][w] != -1)
	{
		return dp[pos][w];
	}
	int ans = INT_MIN;
	int sum = 0;
	for(int i = 0; i < rivals[d+pos].size(); i++)
	{
		int v = rivals[d+pos][i];
		sum += dsp[v];
	}
	cout << pos << " " << sum << " " << ppp[pos] << " " << w << " **\n" ;
	ans = solve_dsp(pos+1,w);	
	if(w-ppp[pos]-sum >= 0)
		ans = max(ans,solve_dsp(pos+1,w-ppp[pos]-sum)-(int)(rivals[d+pos].size())+1);
	return dp[pos][w] = ans;
}

int solve_ppp(int pos, int w)
{
	if(pos > d)
	{
		return 0;
	}
	if(dp[pos][w] != -1)
	{
		return dp[pos][w];
	}
	int ans = INT_MIN;
	int sum = 0;
	for(int i = 0; i < rivals[pos].size(); i++)
	{
		int v = rivals[pos][i];
		sum += ppp[v];
	}
	ans = solve_ppp(pos+1,w);	
	if(w-dsp[pos]-sum >= 0)
		ans = max(ans,solve_ppp(pos+1,w-dsp[pos]-sum)-(int)(rivals[pos].size())+1);
	return dp[pos][w] = ans;
}
main()
{
	while(cin >> d >> p >> r >> b)
	{
		for(int i = 1; i <= d+p; i++)
			rivals[i].clear();
		memset(dp,-1,sizeof(dp));
		for(int i = 1; i <= d; i++)
			cin >> dsp[i];
		for(int i = 1; i <= p; i++)
			cin >> ppp[i];
		for(int i = 0; i < r; i++)
		{
			int x,y;
			cin >> x >> y;
			rivals[x].push_back(y+d);
			rivals[y+d].push_back(x);
		}
		int ans = solve_dsp(1,b);
		memset(dp,-1,sizeof(dp));
		int ans1 = solve_ppp(1,b);
		cout << d + ans << " " << p + ans1 << "\n";
	}
}
