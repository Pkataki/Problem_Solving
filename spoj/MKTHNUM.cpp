#include<bits/stdc++.h>
using namespace std;
struct node
{
	int ls;
	int rs;
	int cont;
}tree[2500005];

int root[100005];

int aux[100005];

int sz;

void update(int &n, int pre, int l, int r, int pos)
{
	n = ++sz;
	tree[n] = tree[pre];
	if(l == r && pos == l)
	{
		tree[n].cont++;
		tree[n].ls = tree[n].rs = 0;
		return;
	}
	int mid = (l+r ) >> 1;
	if(pos <= mid)
		update(tree[n].ls, tree[pre].ls, l , mid, pos);
	else
		update(tree[n].rs, tree[pre].rs, mid+1 , r, pos);

	tree[n].cont = tree[tree[n].ls].cont  + tree[tree[n].rs].cont;
}

int query(int r1, int r2, int l, int r, int k)
{
	if(l == r)
		return l;

	int mid = (l + r) >> 1;
	
	int count = tree[tree[r1].ls].cont - tree[tree[r2].ls].cont;

	if(count >= k)
		return query(tree[r1].ls, tree[r2].ls, l, mid, k);
	
	return query(tree[r1].rs, tree[r2].rs, mid+1, r, k-count);
}


vector<int>v;

int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	
	for(int i = 1; i <= n ; i++)
	{
		scanf("%d",&aux[i]);
		v.push_back(aux[i]);
	}
	
	sort(v.begin(),v.end());
	
	for(int i = 1; i <= n; i++)
	{
		aux[i] = lower_bound(v.begin(),v.end(),aux[i]) - v.begin() + 1;
	}

	update(root[1], 0 , 1, v.size(), aux[1]);

	for(int i = 2; i <= n; i++)
	{
		update(root[i], root[i-1], 1, v.size(), aux[i]);
	}

	while(m--)
	{
		int u , x, k;
		scanf("%d %d %d",&u,&x,&k);
		int idx;
		idx = query(root[x],root[u-1],1,v.size(),k);
		printf("%d\n",v[idx-1]);
	}
	return 0;
}
