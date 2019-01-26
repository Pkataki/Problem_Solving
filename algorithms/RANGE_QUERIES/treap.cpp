#include<bits/stdc++.h>
using namespace std;
struct treap
{
    struct node
    {
        int val,prior,sz,rank,rev;
        node *l, *r;
        node(int val) : val(val), prior(rand()), sz(1), rank(1), l(NULL), r(NULL),rev(0) {}
    };
 
    typedef node * pnode;
 
    pnode root = NULL;
 
    int sz(pnode t)
    {
        return t ? t->sz : 0;
    }
 
    void upd(pnode &t)
    {
        if(t)
        {
            t->sz = 1 + sz(t->l) + sz(t->r);
            t->rank = 1 + sz(t->l);
        }
    }
 
    void split(pnode t, pnode &l, pnode &r, int key)
    {
        if(!t)
            l = r = NULL;
        else if(t->val <= key)
        {
            split(t->r,t->r,r,key);
            l = t;
        }
        else
        {
            split(t->l,l,t->l,key);
            r = t;
        }
        upd(t);
    }
 
    void merge(pnode &t, pnode l , pnode r)
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

    void push (pnode it) 
    {
	    if (it && it->rev) 
	    {
	        it->rev = false;
	        swap(it->l, it->r);
	        if (it->l)  it->l->rev ^= true;
	        if (it->r)  it->r->rev ^= true;
	    }
	}

	// split na posicao
	void split_pos (pnode t, pnode &l, pnode &r, int key, int add = 0) 
	{
	    if (!t)
	        return void( l = r = 0 );
	    push (t);
	    int cur_key = add + sz(t->l);
	    if (key <= cur_key)
	        split_pos (t->l, l, t->l, key, add),  r = t;
	    else
	        split_pos (t->r, t->r, r, key, add + 1 + sz(t->l)),  l = t;
	    upd(t);
	}

	void reverse (pnode t, int l, int r) 
	{
	    pnode t1, t2, t3;
	    split_pos(t, t1, t2, l);
	    split_pos(t2, t2, t3, r-l+1);
	    t2->rev ^= true;
	    merge(t, t1, t2);
	    merge(t, t, t3);
	}

 
    void insert(int val)
    {
        pnode l,r;
        split(root,l,r,val);
        merge(l,l,new node(val));
        merge(root,l,r);
    }
 
    //remove somente um no igual a val
    void del(pnode &t, int val)
    {
        if(!t)
            return;
        if(t->val == val)
            merge(t,t->l,t->r);
        else
            del(val > t->val ? t->r : t->l , val);
        upd(t);
    }
 
    // remove todos os nos igual a val
    void del(int val)
    {
        pnode l,r,m;
        split(root,l,m,val-1);
        split(m,m,r,val);
        merge(root,l,r);
    }
 
    //conta quantos valores menores que val tem na treap
    int count(int val)
    {
        pnode l,r;
        split(root,l,r,val-1);
        int ans = 0;
        if(l)
            ans = sz(l);
        merge(root,l,r);
        return ans;
    }
 
    void dfs(pnode root, int d)
    {
        if(root == NULL)
            return;
        dfs(root->r,d+1);
        printf("%*d\n",5*d,root->val);   
        dfs(root->l,d+1);
    }
     
    int kth(pnode t, int k)
    {
        if(k == t->rank)
            return t->val;
        else if(k < t->rank)
            return kth(t->l, k);
        else
            return kth(t->r, k - t->rank);
    }
};
int main()
{
    
    srand(time(NULL));
    
    treap t;
    return 0;
}