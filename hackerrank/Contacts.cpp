#include<bits/stdc++.h>
using namespace std;
struct node
{
	map<char, node*>link;
	bool end_word;
	int num_pref;
	char c;
	node(){
		num_pref = 0;
	}
};
void insert(node *root, string s)
{
	node *aux = root;
	for(int i = 0; i < s.size(); i++)
	{
		if(!aux->link.count(s[i]))
		{
			node *cur = new node;
			cur->c = s[i];
			cur->end_word = 0;
			cur->num_pref = 0;
			aux->link[s[i]] = cur;
		}
		aux = aux->link[s[i]];
		aux->num_pref++;
	}
}
void search_prefix(node *root ,string s)
{
	node *aux = root;
	for(int i = 0; i < s.size(); i++)
	{
		if(!aux->link.count(s[i]))
		{
			cout << "0\n";
			return;
		}
		aux = aux->link[s[i]];
	}	
	cout << aux->num_pref << "\n";
}
main()
{
	ios_base::sync_with_stdio(0);
	node *trie = new node;
	int n;
	cin >> n;
	while(n--)
	{
		string s,op;
		cin >> op >> s;
		if(op == "add")
			insert(trie,s);
		else
			search_prefix(trie,s);
	}
}
