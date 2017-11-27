#include<bits/stdc++.h>
using namespace std;
struct node
{
	int key,size,priority;
	struct node * left;
	struct node * right;
	node()
	{
		size = 0;
		priority = 0;
		left = right  = NULL;
	}
	node(int _key)
	{
		size = 1;
		key = _key;
		priority = rand();
		left = right = NULL;
	}
	node(int _key, int _priority)
	{
		size = 1;
		key = _key;
		priority = _priority;
		left = right = NULL;
	}
};
struct treap
{
	node *root;
	treap()
	{
		root = NULL;
		srand(time(NULL));
	}
	int tree_size(node *t)
	{
		if(t == NULL)
			return 0;
		return t->size;
	}
	void update_size(node* &t)
	{
		if(t)
			t->size = 1 + tree_size(t->left) + tree_size(t->right);
	}
	void left_rotate(node *&t)
	{
		node * temp = t->left;
		t->left = temp->right;
		temp->right = t;
		t = temp;
		update_size(t->right);
		update_size(t);
	}
	void right_rotate(node *&t)
	{
		node *temp = t->right;
		t->right = temp->left;
		temp->left = t;
		t = temp;
		update_size(t->left);
		update_size(t);
	}
	void insert(node *&t, int _key)
	{
		if(t == NULL)
		{
			t = new node(_key);
		}
		if(_key > t->key)
		{
			insert(t->right,_key);
			if(t->priority < t->right->priority)
				right_rotate(t);
		}
		else if(_key < t->key)
		{
			insert(t->left,_key);
			if(t->priority < t->left->priority)
				left_rotate(t);
		}
		update_size(t);
	}
	void insert(int _key)
	{
		insert(root,_key);
	}
	void del(node *&t, int _key)
	{
		if(t == NULL)
			return;
		if(t->key > _key)
			del(t->left,_key);
		else if(t->key < _key)
			del(t->right,_key);
		else
		{
			if(t->left && t->right)
			{
				if(t->left->priority > t->right->priority)
					left_rotate(t);
				else
					right_rotate(t);
				del(t,_key);
			}
			else
			{
				node *temp = t;
				if(t->left)
					t = t->left;
				else
					t = t->right;
				delete temp;
			}
		}
		update_size(t);
	}
	void del(int _key)
	{
		del(root,_key);
	}
	int count(node *&t, int limit)
	{
		if(t == NULL)
			return 0;
		if(t->key < limit)
			return 1 + tree_size(t->left) + count(t->right,limit);
		else
			count(t->left,limit);
	}
	int count(int limit)
	{
		return count(root,limit);
	}
	int findkth(node *&t, int k)
	{
		if(tree_size(t) < k)
			return INT_MIN;
		int size_left = 1+tree_size(t->left);
		if(k == size_left)
			return t->key;
		
		else if(k < size_left)
			return findkth(t->left,k);
		
		else
			return findkth(t->right,k-size_left);
	}
	int findkth(int k)
	{
		return findkth(root,k);
	}
};
main()
{
	ios_base::sync_with_stdio(0);
	int q;
	cin >> q;
	treap t;
	while(q--)
	{
		char op;
		int num;
		cin >> op >> num;
		if(op == 'I')
			t.insert(num);
		else if(op == 'D')
			t.del(num);
		else if(op == 'C')
			cout << t.count(num) << "\n";
		else if(op == 'K')
		{
			int ans = t.findkth(num);
			if(ans == INT_MIN)
				cout << "invalid\n";
			else
				cout << ans << "\n";
		}
	}
}
