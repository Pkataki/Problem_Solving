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
void search2(string s)
{
//	cout << id << " id\n";
	int x = root;
	//cout << "procurando o Padrao " << str << "\n";
	for(int i = 0; s[i] ; i ++)
	{
		x = target(x , s[i]);
		int state = x;
		cout << "apos o target: "<< state << endl;
		cout << "caracter: "<< s[i] << endl;
		while(state)
		{
			cout << "estado: "<< state << endl;
			for(int j = 0; j < trie[state].matches.size(); j++)
			{
				cout << "Padrao " << trie[state].matches[j].first << " encontrado na posição: " << i - trie[state].matches[j].second + 1 << endl;
			}
			state = trie[state].matchFail;
		}
	}
}


main()
{
	int n;
	nodes = 0;
	root = ++nodes;
	trie[root].matchFail = 0;	
	trie[root].fail = 0;	
	
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		insert(s,i);
	}
	
	adjust_fail();
	for(int i = 1; i <= nodes ; i++)
	{
		cout << "no: " << i << endl;
		cout << "qt matches: " << trie[i].matches.size() << endl;
		cout << "match_fail: " << trie[i].matchFail << endl;
		cout << "fail: " << trie[i].fail << endl;
		cout << "links: " << endl;
		for(map<char,int>::iterator it = trie[i].link.begin(); it != trie[i].link.end(); it++)
			cout << it->second << " " << it->first << endl;
			
		puts("");
	}
	string text;
	cin >> text;
	search2(text);
		
}
