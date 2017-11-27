#include<bits/stdc++.h>
using namespace std;
struct node
{
	vector<int>matches;
	int fail;
	int match_fail;
	map<char,int>next;
};
int nodes,nodes2;
node trie[1000000];
node trie2[1000000];
int root,root2;
int n;
map<string,bool>vis;
void init()
{	
	root = ++nodes;
	trie[root].matches.clear();
	trie[root].fail = 0;
	trie[root].match_fail = 0;
	trie[root].next.clear();
	
	root2 = ++nodes2;
	trie2[root2].matches.clear();
	trie2[root2].fail = 0;
	trie2[root2].match_fail = 0;
	trie2[root2].next.clear();
}
void insert(string s, int id)
{
	int  x = root;
	for(int i = 0; s[i]; i++)
	{
		int &nxt = trie[x].next[s[i]];
		if(!nxt)
			nxt = ++nodes;
		x = nxt;
	}
	trie[x].matches.push_back(id);

}

void insert2(string s, int id)
{
	int  x = root2;
	for(int i = 0; s[i]; i++)
	{
		int &nxt = trie2[x].next[s[i]];
		if(!nxt)
			nxt = ++nodes2;
		x = nxt;
	}
	trie2[x].matches.push_back(id);

}
int target2(int x, char c)
{	
	while(x && !trie2[x].next.count(c))
		x = trie2[x].fail;
	return (x ? trie2[x].next[c] : root2);
}
vector<string> ans;
void construct_strings()
{
	trie[root2].fail = 0;
	queue<int>q;
	q.push(root2);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(map<char,int>::iterator it = trie2[u].next.begin(); it != trie2[u].next.end(); it++)
		{
			int v = it->second;
			char c = it->first;
			int f = target2(v,c);
			trie[v].fail = f;
		}
	}
	queue<pair<string,pair<int,int> > >q1;
	q1.push(make_pair("",make_pair(root2,0)));
	while(!q1.empty())
	{
		string s = q1.front().first;
		int u = q1.front().second.first;
		int num = q1.front().second.second;
		q1.pop();
		cout << s << '\n';
		if(num > n)
			continue;
		if(num == n)
		{
			ans.push_back(s);
			continue;
		}	
		for(map<char,int>::iterator it = trie2[u].next.begin(); it != trie2[u].next.end(); it++)
		{
			int aux;
			aux = (trie[it->second].matches.empty() ? 0 : 1);
			string ns = s + it->first;
			int v = it->second;
			q1.push(make_pair(ns, make_pair(v, num+ aux)));	
		}
//		if(trie[u].matches.size() > 0)
//		{
			int f = trie[u].fail;
			int aux = (trie[f].matches.empty() ? 0 : 1);
			q1.push(make_pair(s,make_pair(f,num+aux)));
//		}
	}
}
int target(int x, char c)
{	
	while(x && !trie[x].next.count(c))
		x = trie[x].fail;
	return (x ? trie[x].next[c] : root);
}
void adjust_fail()
{
	trie[root].fail = 0;
	queue<int>q;
	q.push(root);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(map<char,int>:: iterator it = trie[u].next.begin(); it != trie[u].next.end(); it++)
		{
			int v = it->second;
			char c = it->first;
			int f = target(v,c);
			trie[v].fail = f;
			if(trie[f].matches.empty())
				trie[v].match_fail = trie[f].match_fail;
			else
				trie[v].match_fail = f;
		}
	}
}
bool has_string(string text)
{
	int x = root;
	for(int i = 0; text[i]; i++)
	{
		x = target(x,text[i]);
		int t = x;
		while(t)
		{
			if(!trie[t].matches.empty())
				return true;
			t = trie[t].match_fail;
		}
	}
	return false;
}
main()
{
	int m;
	cin >> n >> m;
	vector<string>v;
	string s;
	init();
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		insert2(s,i);
	}
	construct_strings();
	string ans1 = "";
	int len = INT_MAX;
	if(m)
	{
		for(int i = 0; i < m; i++)
		{
			cin >>s;
			insert(s,i);
		}
		adjust_fail();
		for(int i = 0; i < ans.size(); i++)
		{
			if(!has_string(ans[i]))
			{
					if(ans[i].size() < len)
				{
					len = ans[i].size();
					ans1 = ans[i];
				}
			}
		}
	}
	else
	{
		for(int i = 0; i < ans.size(); i++)
		{
			if(ans[i].size() < len)
			{
				len = ans[i].size();
				ans1 = ans[i];
			}
		}
	}
	cout << "tam: " << ans.size() << '\n';
	cout << ans1 << '\n';
}
