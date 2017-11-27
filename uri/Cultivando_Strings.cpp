#include<bits/stdc++.h>
using namespace std;
int root, nodes;
struct trieNode
{
	bool seen;
	int matchFail;
	//vector< int > matches;
	vector<pair<int,int > > matches;
	int fail;
	map< char, int > link;
} trie[1000005];

void init()
{
	
	root = ++nodes;
	trie[root].link.clear();
	trie[root].matches.clear();
	trie[root].fail = 0;
	trie[root].matchFail = 0;
	trie[root].seen = 0;
	//memset(subst,false,sizeof(subst));
}

void insert(string s, int wordId)
{
	int x = root;
	for (int i = 0; s[i]; ++i)
	{
		int & nxt = trie[x].link[ s[i] ];
		if (!nxt) 
		{
			nxt = ++nodes;
		}
		x = nxt;
	}
	
	//trie[x].matches.push_back(wordId);
	trie[x].matches.push_back(make_pair(wordId,(int)s.size()));
}

inline int target(int x, char ch)
{
	while (x && !trie[x].link.count(ch))
	      x = trie[x].fail;
	      
	return x ? trie[x].link[ch] : root;
}

void adjust_fail()
{
	trie[root].fail = 0; // nil

	queue< int > Q;
	Q.push(root);
	while( !Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (map< char, int >::iterator it = trie[u].link.begin(); it != trie[u].link.end(); ++it)
		{
			char ch = it->first;
			int v = it->second;
			
			int f = target(trie[u].fail, ch);

			Q.push(v);

			trie[v].fail = f;

			if(trie[f].matches.empty())
				trie[v].matchFail = trie[f].matchFail;
			else
				trie[v].matchFail = f;
			
		}
	}
}
vector<vector<int> >graph(10005);
vector<pair<string,int> > v(10005);
void search2(string s, int id)
{
	int x = root;
	for(int i = 0; s[i] ; i ++)
	{
		x = target(x , s[i]);
		int state = x;
		while(state)
		{
			for(int j = 0; j < trie[state].matches.size(); j++)
			{
				
				if(s.size() > trie[state].matches[j].second)
				{
					graph[v[id].second].push_back((int)trie[state].matches[j].first);
				}
			}
			state = trie[state].matchFail;
		}
	}
}


bool cmp(pair<string,int> s, pair<string,int> d)
{
	return s.first.size() < d.first.size();
}
int dp[10005];
int solve(int pos)
{
	if(dp[pos] != -1)
		return dp[pos];
	for(int i = 0; i < graph[pos].size(); i++)
			dp[pos] = max(dp[pos],solve(graph[pos][i]) + 1);
	return dp[pos];
}
main()
{
	int n;
	while(cin >> n && n)
	{
		nodes = 0;
		root = ++nodes;
		for(int i = 0; i <= 10000; i++)
		{
			dp[i] = -1;
			graph[i].clear();
		}
		for(int i = 0; i <= 1000000; i++)
		{
			trie[i].link.clear();
			trie[i].matches.clear();
			trie[i].matchFail = 0;	
			trie[i].fail = 0;	
		}
		for(int i = 0; i < n; i++)
		{
			cin >> v[i].first;
			insert(v[i].first,i);
			v[i].second = i;
		}
	
		adjust_fail();		
		
		int maior = 0;
		for(int i = 0; i < n; i++)
		{
			search2(v[i].first, v[i].second);
		}
		
		for(int i = 0; i < n; i++)
			maior = max(maior,solve(i)+1);
		
		cout << maior+1 <<  "\n" ;
	}
}
