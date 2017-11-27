#include<bits/stdc++.h>
using namespace std;
vector<int>v1(10005);
vector<int>v2(10005);
int n1,n2;
long long dp[10005][2];
int bs(int val, vector<int>v)
{
	int lo = 0;
	int hi = v.size()-1;
	while(lo <= hi)
	{
		int mid = (lo+hi)/2;
		if(val > v[mid])
		{
			lo = mid+1;
		}
		else if(val < v[mid])
		{
			hi = mid-1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
	
}
long long solve(int pos, int line)
{
	if((line == 0 && pos == n1) || (line == 1 && pos == n2))
		return 0LL;
	if(dp[pos][line] != -1)
		return dp[pos][line];
	long long ans = 0LL;
	if(!line)
	{
		
		ans = solve(pos+1,line) + v1[pos];
		int idx = bs(v1[pos],v2);
	//	cout << pos << " " << line << " " << idx << " "  << v1[pos] <<" **\n";
		if(idx != -1)
			ans = max(ans,solve(idx+1,1)+v2[idx]);
	}
	else
	{
		ans = solve(pos+1,line) + v2[pos];
		int idx = bs(v2[pos],v1);
	//	cout << pos << " " << line << " " << idx << " "  << v2[pos] <<" **\n";
		if(idx != -1)	
			ans = max(ans,solve(idx+1,0)+v1[idx]);
	}
	return dp[pos][line] = ans;
}
main()
{
	while(cin >> n1 && n1)
	{
		memset(dp,-1,sizeof(dp));
		v1 = vector<int>(n1);
		for(int i = 0; i < n1 ;i++)
		{
			cin >> v1[i];
		}
		cin >> n2;
		v2 = vector<int>(n2);
		for(int i = 0; i < n2; i++)
		{
			cin >> v2[i];
		}
		cout << max(solve(0,0),solve(0,1)) << "\n";
	}
}
