#include<bits/stdc++.h>
using namespace std;
struct state
{
	int link;
	map<char,int>next;
	long long len;
};
state st[550000];
int sz;
int last;
void init()
{
	sz = 1;
	last = 0;
	st[0].link = -1;
	st[0].len = 0;
	st[0].next.clear();
}
long long ans;
void sa_extend(char c)
{
	int cur = sz++;
	st[cur].len = st[last].len + 1;
	st[cur].next.clear();
	int p = last;
	while(p != -1 && !st[p].next.count(c))
	{
		st[p].next[c] = cur;	
		p = st[p].link;
	}
	if(p == -1)
	{
		st[cur].link = 0;
	}
	else
	{
		int q = st[p].next[c];
		if(st[p].len + 1 == st[q].len)
		{
			st[cur].link = q;
		}
		else
		{
			int clone = sz++;
			st[clone] = st[q];
			st[clone].len = st[p].len+1;
			while( p != -1 && st[p].next[c] == q )
			{
				st[p].next[c] = clone;
				p = st[p].link;
			}
			st[cur].link = st[q].link = clone;
		}
	}
	ans += (st[cur].len - st[st[cur].link].len);
	last = cur;
}
main()
{
	ios_base::sync_with_stdio(0);
	string s;
	while(cin >> s)
	{
		ans = 0;
		init();
		for(int i = 0; s[i]; i++)
		{
			if(s[i] != '?')
				sa_extend(s[i]);
			else
			{
				cout << ans << '\n';
			}
		}
		for(int i = 1; i <= sz; i++)
		{
			st[i].next.clear();
			st[i].len = 0;
			st[i].link = -1;
		}
	}
}