#include<bits/stdc++.h>

#define MAXN 1000001000

using namespace std;

//indexada a partir de 1
typedef struct item * pitem;

struct item {
	int prior, value, cnt;
	int ma;
	bool rev;
	pitem l, r;

	item(int _value){
		ma = value = _value;
		prior = rand();
		l = r = 0;
	}
};
int cnt (pitem it) {
	return it ? it->cnt : 0;
}

//alterar de acordo com o problema
int Ma (pitem it) {
	return it ? it->ma : 0;
}


void upd_cnt (pitem it) {
	if (it){
		it->cnt = cnt(it->l) + cnt(it->r) + 1;
		
		//alterar de acordo com o problema
		it->ma = max(it->value, max( Ma(it->l), Ma(it->r) )  );
	}
}


//alterar de acordo com o problema
void push (pitem it) {
	if (it && it->rev) {
		it->rev = false;
		swap (it->l, it->r);
		if (it->l)  it->l->rev ^= true;
		if (it->r)  it->r->rev ^= true;
	}
}

void merge (pitem & t, pitem l, pitem r) {
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
	upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
	if (!t)
		return void( l = r = 0 );
	push (t);
	int cur_key = add + cnt(t->l);
	if (key <= cur_key)
		split (t->l, l, t->l, key, add),  r = t;
	else
		split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
	upd_cnt (t);
}

void reverse (pitem t, int l, int r)
{
	pitem t1, t2, t3;
	split (t, t1, t2, l);
	split (t2, t2, t3, r-l+1);
	t2->rev ^= true;
	merge (t, t1, t2);
	merge (t, t, t3);
}

void insert(pitem &T, int pos, int value)
{
	pos--;
	pitem l, r;
	split(T, l, r, pos);
	pitem new_item = new item(value);
	merge(l, l, new_item);
	merge(T, l, r);
}
/*
void output (pitem t, int dep) {
	if (!t)  return;
	push (t);
	output (t->r,dep+1);
	printf ("%*d\n",dep, t->value);
	output (t->l,dep+1);
}*/
int arr[2223456];
int sz = 1;

void output (pitem t) {
    if (!t)  return;
    push (t);
    output (t->l);
    arr[sz++] = t->value;
    output (t->r);
}

int del(pitem &T, int pos)
{
	pos--;
	pitem t1,t2;
	split(T, T, t1, pos);
	split(t1, t1, t2, 1);
	int ans = t1->value - MAXN;
	merge(T, T, t2);
	return ans;
}
void cyclicShift(pitem &t, int l, int r) {
  int sz = r - l + 1;

  if(sz == 1) return;

  pitem t1, t2, t3, t4;
  split (t, t1, t2, l);
  split (t2, t2, t3, sz);

  split(t2, t2, t4, sz - 1);
  merge(t2, t4, t2);

  merge (t, t1, t2);
  merge (t, t, t3);
}
int range_query(pitem &T, int l, int r)
{
	l--, r--;
	pitem t1, t2;
	split(T, T, t1, l);
	split(t1, t1, t2, r-l+1); 
	int ans = t1->ma - MAXN;
	merge(t1, t1, t2);
	merge(T, T, t1);
	return ans;
}

int main()
{
	srand(time(NULL));
	int n;
	
	pitem T = NULL;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		char c;
		int a, b;
		scanf(" %c %d %d",&c, &a, &b);
		if(c != 'Q')
		{
			insert(T,b, a+MAXN);	
		}
		else
		{
			printf("%d\n",range_query(T,a,b));	
		}
		
	}
	return 0;
}
