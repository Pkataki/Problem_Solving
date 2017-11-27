#include<bits/stdc++.h>
using namespace std;
int v[100005];
struct node
{
	node * next[2];
	node()
	{
		next[0] = NULL;
		next[1] = NULL;
	}
};
void insert(node * trie, int num)
{
	node *temp = trie;
	for(int i = 31; i >= 0 ; i--)
	{
		int bit = (num & (1 << i));
		if(temp->next[bit] == NULL)
			temp->next[bit] = new node();
		temp = temp->next[bit];
	}
}
int query(node * trie, int num)
{
	node *temp = trie;
	int ans = 0;
	for(int i = 31; i >= 0 ; i--)
	{
		int bit = (num & (1 << i));
		if(temp->next[1-bit] != NULL)
		{
			ans |= (1 << i);
			temp = temp->next[1-bit];
		}
		else if(temp->next[bit] != NULL)
			temp = temp->next[bit];
			
	}
	return ans;
}
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		node * trie = new node();
		int pre = 0;
		int ans = 0;
		for(int i = 0 ; i < n ; i++)
		{
			int a;
			cin >> a;
			pre ^= a;
			insert(trie,pre);
			ans = max(ans,query(trie,pre));
		}
		cout << ans << '\n';
	}
	return 0;
}
