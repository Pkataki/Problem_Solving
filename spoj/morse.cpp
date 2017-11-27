#include<bits/stdc++.h>
using namespace std;
map<char,string>m;
typedef struct trie
{
	bool fim;
	struct trie *child[26];
	trie()
	{
		for(int  i = 0; i < 26; i++)
			child[i] = NULL;
	}
}trie;
void add_word(trie* T, string s)
{
	if(s == "")
	{
		T->fim = 1;
		return; 
	}
	int idx = s[0] - 'A';
	if(T->child[idx] == NULL)
	{
		T->child[idx] = new trie();
	}
	add_word(T->child[idx],s.substr(1));
}
vector<string>morse(20);
int n,d;
main()
{
	trie *T = new trie();
	m['A'] = ".-";
	m['B'] = "-...";
	m['C'] = "-.-.";
	m['D'] = "-.."; 
	m['E'] = ".";
	m['F'] = "..-.";
	m['G'] = "--.";
	m['H'] = "....";
	m['I'] = "..";
	m['J'] = ".---";
	m['K'] = "-.-";
	m['L'] = ".-..";
	m['M'] = "--";
	m['N'] = "-.";
	m['O'] = "---";
	m['P'] = ".--.";
	m['Q'] = "--.-";
	m['R'] = ".-.";
	m['S'] = "...";
	m['T'] = "-"; 
	m['U'] = "..-";
	m['V'] = "...-";
	m['W'] = ".--";
	m['X'] = "-..-";
	m['Y'] = "-.--";
	m['Z'] = "--..";
	cin >> d;
	for(int i = 0; i < d; i++)
	{
		cin >> morse[i];
	}
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		add_word(T,a);
	}

}
