#include<bits/stdc++.h>
using namespace std;
string s;
int tree[4500000];
int lazy[4500000];
/*
	1 - flip
	2 - Buccaneer
	3 - Barbary
*/
void build(int node, int l, int r)
{
	if(l > r)
		return;
	lazy[node] = 0;
	if(l == r)
	{
		tree[node] = s[l] - '0';
		return;
	}
	int mid = (l + r) >> 1;
	build(node*2,l,mid);
	build(node*2+1,mid+1,r);
	tree[node] = tree[2*node] + tree[node*2+1];
}
int flip(int x)
{
	if(x == 2)
		return 3;
	else if(x == 3)
		return 2;
	else if(x == 1)
		return 0;
	else
		return 1;
	/*o ultimo else foi um chute*/
}

void push(int node, int l, int r)
{
	if(lazy[node] != 0)
	{
		if(lazy[node] == 2)
		{
			tree[node] = (r - l) + 1;

		}
		else if(lazy[node] == 1)
		{
			int aux = tree[node];
			tree[node] = (r - l) + 1 - aux;
		}
		else if(lazy[node] == 3)
		{
			tree[node] = 0;
		}
		if(l != r)
		{
			if(lazy[node] == 3 || lazy[node] == 2)
			{
				lazy[node*2] = lazy[node];
				lazy[node*2+1] = lazy[node];
			}
			else
			{
				lazy[node*2] = flip(lazy[node*2]);
				lazy[node*2+1] = flip(lazy[node*2+1]);	
			}
		}	
		lazy[node] = 0;
	}
}
int query(int node, int l, int r, int x, int y)
{
	if(l > r || l > y || r < x)
		return 0;	
	push(node,l,r);
	if(l >= x && r <= y)
	{
		return tree[node];
	}
	int mid = (l + r) >> 1;
	push(node*2,l,mid);
	push(node*2+1,mid+1,r);
	int p1 = query(node*2, l, mid,x,y);	
	int p2 = query(node*2+1, mid+1,r,x,y);
	return p1+p2;
}
void update(int node, int l, int r, int x, int y, int tipo)
{
	if(l > r || l > y || r < x)
		return;
	push(node,l,r);
	if(l >= x && r <= y)
	{
		lazy[node] = tipo;
		push(node,l,r);
		return;
	}
	int mid = (l + r) >> 1;
	push(node*2,l,mid);
	push(node*2+1,mid+1,r);
	update(node*2,l,mid,x,y,tipo);
	update(node*2+1,mid+1,r,x,y,tipo);
	tree[node] = tree[node*2] + tree[node*2+1];
}
main()
{
	int test;
	cin >> test;
	for(int t = 1; t <= test; t++)
	{
		cout << "Case "<< t << ":\n";
		int n;
		s = "";
		cin >> n;
		while(n--)
		{
			int m;
			cin >> m;
			string aux;
			cin >> aux;
			for(int i = 0; i < m; i++)
				s += aux;
		}
		build(1,0,s.size()-1);
		int q;
		cin >>q;
		int cont = 0;
		while(q--)
		{
			char c;
			int a,b;
			cin >> c >> a >> b;
			if(c == 'F')
			{
				update(1,0,s.size()-1,a,b,2);
			}
			else if(c == 'E')
			{
				update(1,0,s.size()-1,a,b,3);
			}
			else if(c == 'I')
			{
				update(1,0,s.size()-1,a,b,1);	
			}
			else
			{
				cout << "Q" << ++cont << ": " << query(1,0,s.size()-1,a,b) << "\n";
			}
		}

	}
}
