#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int in[MAXN];
int out[MAXN];
int cont;
vector<int>graph[MAXN];

int label[MAXN];
int val1[MAXN];
int val[MAXN];
unordered_map<int,int>mapa;
struct node
{
	int ls;
	int rs;
	int cont;
}tree[MAXN*20];

int root[MAXN];


int sz;
#define getcx getchar_unlocked
#define pc(x) putchar_unlocked(x)

 
inline int readInt()
{
    bool minus = false;
    register int result = 0;
    register char ch = getchar_unlocked();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break ;
        ch = getchar_unlocked();
    }
    if (ch == '-') minus = true; 
    else result = ch-'0';
    while (true)
    {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus) return -result;
    else return result;
}
 
inline void writeInt ( int n )
{
    register int N = n, rev, count = 0 ;
    rev = N ;
    if (N == 0) 
    { 
        pc('0');  return ;
    }
    while ((rev % 10) == 0) 
    { 
        count++; rev /= 10;
    } //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) 
    { 
        rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;
    }  //store reverse of N in rev
    while (rev != 0) 
    { 
        pc(rev % 10 + '0'); rev /= 10 ;
    }
    while (count--) pc('0') ;
}
void update(int &n, int pre, int l, int r, int pos)
{
	if(l > r)
		return;
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

int dfs(int u, int pai)
{
	in[u] = cont++;
	
	for(int i = 0 ; i < graph[u].size(); i++)
	{
		if(graph[u][i] != pai)
			dfs(graph[u][i],u);
	}
	out[u] = cont-1;
}
int main()
{
	cont = 1;
	int n;
	n = readInt();
	int pos[n];
	for(int i = 1 ; i <= n ; i++)
	{
	 	label[i] = readInt();
	 	pos[i-1] = label[i];
	}
	sort(pos, pos + n);
	int p = unique(pos, pos + n) - pos;
	for (int i = 1; i <= n; ++ i) 
	{
		label[i] = (lower_bound(pos, pos + p, label[i]) - pos)+1;
		mapa[label[i]] = i;
		
	}
	for(int i = 0; i < n -1; i++)
	{
		int u,v;
		u = readInt();
		v = readInt();
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	dfs(1,-1);
	for(int i = 1; i<= n ; i++)
	{
		val1[in[i]] = i;
		val[in[i]] = label[i];
	}
	update(root[1], 0 , 1, n, val[1]);

	for(int i = 2; i <= n; i++)
	{
		update(root[i], root[i-1], 1, n, val[i]);
	}
	
	int q; 
	q = readInt();
	while(q--)
	{
		int x,k;
		x = readInt();
		k = readInt();
		int l = in[x];
		int r = out[x];
		int ans = query(root[r], root[l-1], 1, n, k);
		writeInt(mapa[ans]);
		pc('\n');
	}
	
	return 0;
}
