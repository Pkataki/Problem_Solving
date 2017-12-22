#include<bits/stdc++.h>
using namespace std;

const int
	MAXL = 1 << 17,
	MAXN = 1 << 10;

int N;
char text[MAXL];
char buf[MAXL];
//bool subst[MAXN];

int root, nodes;
struct trieNode
{
	bool seen;
	int matchFail;
	//vector< int > matches;
	vector<pair<int,int > > matches;
	int fail;
	map< char, int > link;
} trie[MAXL];

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

void insert(char * s, int wordId)
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
	trie[x].matches.push_back(make_pair(wordId,(int)strlen(s)));
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
/*
void search()
{
	int x = root;
	for (int i = 0; text[i]; ++i)
	{
		
		x = target(x, text[i]);

		for (int t = x; t && !trie[t].seen; t = trie[t].matchFail)
		{
			trie[t].seen = true;
			for(int j = 0; j < trie[t].matches.size(); j++)
				subst[trie[t].matches[j]] = true;
		}
	}
}
*/
void search2()
{
	int x = root;
	//cout << "procurando o Padrao " << str << "\n";
	for(int i = 0; text[i] ; i ++)
	{
		x = target(x , text[i]);
		int state = x;
		while(state)
		{	
			for(int j = 0; j < trie[state].matches.size(); j++)
			{
				cout << "Padrao " << trie[state].matches[j].first << "encontrado na posição " << i - trie[state].matches[j].second + 1 << "\n";
			}
			state = trie[state].matchFail;
		}
	}
}
int main()
{
	init();
	scanf( "%s", &text );
	scanf( "%d", &N );
	
	for(int i = 0; i < N; i++)
	{
		scanf( "%s", &buf );
		insert(buf, i);
		//cout << "sdads";
	}
	
	adjust_fail();

	//string arr[] = {"he", "she", "hers", "his"};
	cout << "insira\n";
		search2();
	
	/*
	for(int i = 0; i < N; i++)
	      printf( "%s\n", subst[i] ? "Y" : "N" );
	*/

	return 0;
}
