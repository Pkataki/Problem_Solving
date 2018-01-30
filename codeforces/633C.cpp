#include<bits/stdc++.h>
using namespace std;
string v[100005];
vector<int>ans;
string text;
struct node
{
	int nxt[30];
	int id;
}trie[1000005];

int nodes = 1;
void insert(string s, int id)
{
	int x = 1;
	for(int i = s.size()-1 ; i >= 0 ; i--)
	{	
		int ch = tolower(s[i]) - 'a';
		if(trie[x].nxt[ch] == 0)
			trie[x].nxt[ch] = ++nodes;

		x = trie[x].nxt[ch];
	}
	trie[x].id = id;
}
void solve(int pos)
{
	//cout << pos << endl;
	if(pos >= text.size())
	{
		//cout << ans.size() << '\n';
		for(int i = 0; i < ans.size(); i++)
		{
			cout << v[ans[i]] << ' ';
		}
		cout << '\n';
		exit(0);
	}
	int x = 1;
	for(int i = pos; i < text.size(); i++)
	{
		int ch = text[i] - 'a';
		if(trie[x].nxt[ch] == 0)
			break;
		//cout << "tem " << endl;
		x = trie[x].nxt[ch];
		if(trie[x].id)
		{
			ans.push_back(trie[x].id);
			
			solve(pos + v[trie[x].id].size());
			
			ans.pop_back();
		}
	}
}
int main()
{
	int n;
	cin >> n;
	cin >> text;
	int m;
	cin >> m;
	for(int i = 1; i <= m ; i++)
	{
		cin >> v[i];
		insert(v[i],i);
	}
	solve(0);
	return 0;
}
