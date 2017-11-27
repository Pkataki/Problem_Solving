#include<bits/stdc++.h>
using namespace std;
int v[1 << 18];
int tree1[1 << 19];
int tree2[1 << 19];
void init(int node, int l , int r)
{
	if(l > r)
		return;
	if(l == r)
	{
		tree1[node] = tree2[node] = v[l];
		return;
	}
	int mid = (l + r) >> 1;
	init(node*2, l, mid);
	init(node*2+1, mid+1, r);
	tree1[node] = tree2[node*2] | tree2[2*node+1];
	tree2[node] = tree1[node*2] ^ tree1[2*node+1];
}
void update(int node, int l, int r, int pos)
{
	if(l == r)
	{
		tree1[node] = tree2[node] = v[l];
		return;	
	}
	int mid = (l + r) >> 1;
	if(pos <= mid)
		update(node*2,l,mid,pos);
	else
		update(node*2,mid+1,r,pos);
	
	tree1[node] = tree2[node*2] | tree2[2*node+1];
	tree2[node] = tree1[node*2] ^ tree1[2*node+1];
}
int main()
{
	int n,q;
	cin >> n >> q;
	for(int i = 0 ; i < (1 << n); i++)
	{
		cin >> v[i];
	}
	init(1,0,(1 << n)-1);
	while(q--)
	{
		int pos,val;
		cin >> pos >> val;
		v[pos] = val;
		update(1,0,(1 << n)-1,pos);
		if(n&1)
			cout << tree2[1] << '\n';
		else
			cout << tree1[1] << '\n';
	}

}
