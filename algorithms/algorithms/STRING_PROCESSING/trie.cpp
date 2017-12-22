#include<bits/stdc++.h>
using namespace std;
struct node
{
	char c;
	map< char , node * > link;
	bool end_word;
	node(){}
};
bool insert(node *root,	string s)
{
	node *aux = root;	
	for(int i = 0; i < s.size(); i++)
	{
		if(aux->end_word == 0)
		{
			if(aux->link.count(s[i]) == 0)
			{
				node *cur = new node;
				cur->c = s[i];
				cur->end_word = false;
				aux->link[s[i]] = cur;
			}
			else
			{
				if(i == s.size() - 1)
					return false;
			}
			aux = aux->link[s[i]];
		}
		else
			return false;
	}
	aux->end_word = true;	
	return true;
}
int main()
{
	node *trie = new node;
	int n;
	cin >> n;
	vector<string>words(n);
	for(int i = 0; i < n; i++)
	{
		cin >> words[i];
	}
	bool bad = 0;
	for(int i = 0; i < words.size(); i++)
	{
		if(!insert(trie,words[i]))
		{
			cout << "BAD SET\n";
			cout << words[i] << "\n";
			bad = 1;
			break;
		}
	}
	if(!bad)
		cout << "GOOD SET\n";
	return 0;
}
