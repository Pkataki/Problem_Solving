#include<bits/stdc++.h>
using namespace std;
struct state
{
	int len,link;
	map<char,int>next;
};
const int MAXLEN = 100000;
state st[MAXLEN*2];
int sz, last;
void sa_init()
{
	sz = last = 0;
	st[0].len = 0;
	st[0].link = -1;
	++sz;
}
void sa_extend(char c)
{
	int cur = sz++;
	st[cur].len = st[last].len + 1;
	int p;
	for(p = last; p != -1 && !st[p].next.count(c); p = st[p].link)
		st[p].next[c] = cur;
	if(p == -1)
	{
		st[cur].link = -1;
	}
	else
	{
		int q = st[p].next[c];
		if(st[p].len + 1 == st[q].len)
			st[cur].link = q;
		else
		{
			int clone = sz++;
			st[clone].len = st[p].len + 1;
			st[clone].next = st[p].next;
			st[clone].link = st[p].link;
			for(; p != -1 && st[p].next[c] == q ; p = st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}
int pos_ith[100000];
int dp[100000];
int n,a,b;
int solve(int pos)
{
	if(pos == n)
		return 0;
	if(dp[pos] != -1)
		return dp[pos];
	dp[pos] = 0;
	int ans = 0;
	ans = max(solve(pos+1)+a,solve(pos+pos_ith[pos])+b)
	return dp[pos]=ans;
}
main()
{
	int test;
	cin >> test;
	while(test--)
	{
		cin >> n >> a >> b;
		string s;
		cin >> s;
		sa_init();
		pos_ith[0] = 0;
		sa_extend(s[0]);
		for(int i = 0; i < n; i++)
		{
			int v,l,r;
			v = l = r = 0;
			for(int j = i; j < n && st[v].next.count(s[j]))
			{
				v = st[v].next[s[j]];
				++l;
				j++;
			}
			sa_extend(s[i]);
			pos_ith[i] = l;
		}
		memset(dp,-1,sizeof(dp));

	}
}
