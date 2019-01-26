#include<bits/stdc++.h>
using namespace std;
/*
SegmentTree merge( SegmentTree a , SegmentTree b)
{
    SegmentTree res ;

    res.Sum = a.Sum + b.Sum ;

    res.maxSum = max( max( a.maxSum , b.maxSum ) , (a.suffixSum + b.prefixSum ) ) ;

    res.prefixSum = max( a.prefixSum , a.Sum + b.prefixSum );

    res.suffixSum = max( b.suffixSum , b.Sum + a.suffixSum );

    return res ;
}*/

int inf = 1e8;
struct treap
{
	struct node
	{
		int sum;
		int val;
		int pref;
		int suf;
		int max_sum;
		int prior;
		int sz;
		node *l, *r;
		node(int val) : val(val), sum(val), pref(val), max_sum(val), suf(val), prior(rand()), r(NULL), l(NULL), sz(1) {}
	};

	typedef node * pnode;

	pnode root = NULL;

	int sz(pnode t)
	{
		return t ? t->sz : 0;
	}

	int sum(pnode t)
	{
		return t ? t->sum : 0;
	}

	int pref(pnode t)
	{
		return t ? t->pref : 0;
	}
	
	int suf(pnode t)
	{
		return t ? t->suf : 0;
	}
	
	int max_sum(pnode t)
	{
		return t ? t->max_sum : -inf;
	}

	void upd(pnode &t)
	{
		if(t)
		{
			t->sz = 1 + sz(t->l) + sz(t->r);
			t->sum = t->val + sum(t->l) + sum(t->r);
			t->max_sum = max(max(max_sum(t->l), max_sum(t->r)) , max(0,suf(t->l)) + t->val + max(0,pref(t->r)));
			t->pref = max(pref(t->l), sum(t->l) + t->val + max(0,pref(t->r)));
			t->suf = max(suf(t->r), t->val + sum(t->r) + max(0,suf(t->l)));
		}
	}
	
	void merge(pnode &t, pnode l, pnode r)
	{
		if(!l || !r)
		{
			t = l ? l : r;
		}
		else if(l->prior > r->prior)
		{
			merge(l->r,l->r,r);
			t = l;
		}
		else
		{
			merge(r->l,l,r->l);
			t = r;
		}
		upd(t);
	}

	void split(pnode t, pnode &l, pnode &r, int pos, int add = 0)
	{
		if(!t)
		{
			l = r = NULL;
			return ;
		}
		int cur = sz(t->l) + add;
		if(cur >=  pos)
		{
			split(t->l,l,t->l,pos,add);
			r = t;
		}
		else
		{
			split(t->r,t->r,r,pos,cur+1);
			l = t;
		}
		upd(t);
	}


	void insert(int pos, int val)
	{
		pnode l,r;
		split(root,l,r,pos-1);
		merge(l,l,new node(val));
		merge(root,l,r);
	}

	void del(int pos)
	{
		pnode l,r,m;
		split(root,l,r,pos);
		split(l,l,m,sz(l)-1);
		merge(root,l,r);
	}

	void replace(int pos, int val)
	{
		del(pos);
		insert(pos,val);
	}

	int query(int ls,int rs)
	{
		pnode l,r,m;
		split(root,l,r,ls-1);
		split(r,m,r,rs-ls+1);
		int ans = 0;
		if(m)
			ans = m->max_sum;
		merge(root,l,m);
		merge(root,root,r);
		return ans;
	}

	void output(pnode t)
	{
		if(!t)
			return;
		output(t->l);
		cout << t->val << " ";
		output(t->r);
	}
};
int main()
{

	int n;
	scanf("%d",&n);

	treap t;
	for(int i = 1; i <= n ; i++)
	{
		int a;
		scanf("%d",&a);
		t.insert(i,a);
	}
	int m;
	
	scanf("%d",&m);

	while(m--)
	{
		char op;
		scanf(" %c",&op);
		if(op == 'I')
		{
			int pos,val;
			scanf("%d %d",&pos,&val);
			t.insert(pos,val);
		}
		else if(op == 'D')
		{
			int pos;
			scanf("%d",&pos);
			t.del(pos);
		}

		else if(op == 'R')
		{
			int pos,val;
			scanf("%d %d",&pos,&val);
			t.replace(pos,val);			
		}

		else
		{
			int l,r;
			scanf("%d %d",&l,&r);
			printf("%d\n",t.query(l,r));
		}
	}
	return 0;
}