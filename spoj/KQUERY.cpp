#include<bits/stdc++.h>
using namespace std;
int v[30005];
vector<int>tree[4*30005];
void init(int node, int lo, int hi)
{
	if(lo == hi)
	{
		tree[node].push_back(v[lo]);
		return ;
	}
	int mid = (lo+hi) >> 1;
	init(node*2+1,lo,mid);
	init(node*2+2,mid+1,hi);
	tree[node].resize(tree[node*2+1].size()+tree[node*2+2].size());
	merge(tree[node*2+1].begin(),tree[node*2+1].end(),tree[node*2+2].begin(),tree[node*2+2].end(),tree[node].begin());
}
int query(int node, int lo ,int hi, int x, int y, int k)
{
	if(lo > y || hi < x || lo > hi)
		return 0;
	if(x <= lo && hi <= y)
	{
		vector<int>::iterator it = upper_bound(tree[node].begin(),tree[node].end(),k);
		return tree[node].end() - it;
	}
	int mid = (lo+hi) >> 1;
	int p1 = query(node*2+1,lo,mid,x,y,k);
	int p2 = query(node*2+2,mid+1,hi,x,y,k);
	return p1+p2; 
}
main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	init(0,0,n-1);
	int q;
	cin >> q;
	int last_ans = 0;
	while(q--)
	{
		int i,j,k;
		cin >> i >> j >> k;
		
		i = i ^ last_ans;
		j = j ^ last_ans;
		k = k ^ last_ans;
		i--;
		j--;
		last_ans = query(0,0,n-1,i,j,k);
		
		cout << last_ans << "\n";
	}
}
