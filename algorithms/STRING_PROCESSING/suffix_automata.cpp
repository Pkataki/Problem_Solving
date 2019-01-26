#include<bits/stdc++.h>
using namespace std;
const int MAXLEN = 100005;

struct automaton
{
	struct state
	{
		int link;
		int next[27];
		int len;
		int mask;
	};
	state st[4*MAXLEN];
	int sz;
	void sa_init()
	{
		for(int i = 0 ; i < sz ; i++)
		{
			memset(st[i].next,0,sizeof(st[i].next));
			st[i].len = 0;
			st[i].mask = 0;
		}
		sz = 1;
		last = 0;
		st[0].link = -1;
		st[0].len = 0;
		st[0].mask = 0;
		memset(st[0].next,0,sizeof(st[0].next));
	}
	int last = 0;
	void sa_extend(int c, int id)
	{
		int cur = sz++;
		st[cur].len = st[last].len + 1;
		st[cur].mask |= (1 << id);
		int p = last;
		while(p != -1 && !st[p].next[c])
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
		last = cur;
	}
	int sa_counting(int val)
	{
		int ans = 0;
		int p = 0;
		memset(deg,0,sizeof(deg));
		for(int i = 1 ;  i < sz  ;  i++  )
			deg[st[i].link]++;
		for(int i = 1 ;  i < sz  ;  i++  )
		{
			if( deg[i] == 0 )
				q[++p] = i;
		}
		while( p > 0 )
		{
			int k = q[p];
			p--;
			if(k <= 0)
				break;
			st[st[k].link].mask |= st[k].mask;
			if(st[k].mask == val)
				ans = max(ans,st[k].len);
			if(  (--deg[st[k].link] ) == 0  )
				q[++p] = st[k].link;
		
		}
			
		return ans;
	}
}a;
