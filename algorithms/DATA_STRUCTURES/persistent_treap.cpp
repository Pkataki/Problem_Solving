#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005;
const int maxm = 30000005;
struct node
{
	static node nodes[maxm];
	node *l,*r;
	char c;
	int prior,sz;
	node(char c) : c(c), sz(1), l(NULL), r(NULL), prior(rand()) {}
	node(){}
}node :: nodes[maxm], *ptr=node::nodes;

typedef node * pnode;

pnode roots[maxn];


struct persistent_treap
{

	int p = 0;
	
	int sz(pnode t)
	{
		return t ? t->sz : 0;
	}

	void upd(pnode &t)
	{
		if(t)
		{
			t->sz = sz(t->l) + sz(t->r) + 1;
		}
	}
 
 
	pnode merge( pnode l, pnode r)
	{
		if(!l || !r)
		{
			return l ? l : r;	
		}
		pnode ans;
		if(l->prior > r->prior)
		{
			ans = new(ptr++) node(*l);
			ans->r = merge(l->r,r);
		}
		else
		{
			ans = new(ptr++) node(*r);
			ans->l = merge(l,r->l);
		}
		upd(ans);
		return ans;
	}
 
	void split(pnode t, pnode &l, pnode &r, int k) 
	{
	    if (!t) 
	    	l = r = NULL;
	    else if (sz(t->l) + 1 <= k) 
	    {
	        l = new(ptr++) node(*t);
	        split(t->r,l->r,r,k-sz(t->l)-1);
	        upd(l);
	    }
	    else {
	        r = new(ptr++) node(*t);
	        split(t->l,l,r->l,k);
	        upd(r);
	    }
	}

	void print(pnode t)
	{
		if(!t)
			return;
		print(t->l);
		printf("%c",t->c);
		if(t->c == 'c')
			p++;
		print(t->r);
	}

	void insert(pnode &root, char s[], int n, int p)
	{
		pnode l,r;
		split(root,l,r,p);
		for(int i = 0; i < n; i++)
		{
			l = merge(l, new(ptr++) node(s[i]));
		}
		root = merge(l,r);
	}

	void del(pnode &root, int p, int n)
	{
		pnode l,r,m;
		split(root,l,r,p-1);
		split(r,m,r,n);
		root = merge(l,r);
	}

	void print_query(pnode &root, int p, int n)
	{
		pnode l,r,m;
		split(root,l,r,p-1);
		split(r,m,r,n);
		print(m);
		puts("");
	}
};
const int maxp = 1000005;
char s[maxp];

int main()
{
	int q;
	scanf("%d",&q);
	persistent_treap t;
	int ver = 0;
	roots[ver] = NULL;
	srand(time(NULL));
	ptr = node::nodes;
	while(q--)
	{
		int op;
		scanf("%d",&op);
		if(op == 1)
		{
			int p;
			scanf("%d %s",&p,s);
			p -= t.p;
			ver++;
			int n = strlen(s);
			roots[ver] = roots[ver-1];
			t.insert(roots[ver],s,n,p);
			
		}
		else if(op == 2)
		{
			int p,n;
			scanf("%d %d",&p,&n);
			p -= t.p;
			n -= t.p;
			ver++;
			roots[ver] = roots[ver-1];
			t.del(roots[ver],p,n);	
		}
		else if(op == 3)
		{
			int v,p,n;	
			scanf("%d %d %d",&v, &p, &n);
			p -= t.p;
			v -= t.p;
			n -= t.p;
			t.print_query(roots[v],p,n);
			
		}
	}
	return 0;
}
 
