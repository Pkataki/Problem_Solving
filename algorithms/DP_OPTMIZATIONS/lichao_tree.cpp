
const int maxn = 100005;
long long a[maxn];
long long b[maxn];
vector<int>graph[maxn];

const long long inf = 1e7;
struct line
{
	long long a,b;
	line()
	{
		a = -inf;
		b = -inf;
	}
	line(long long a, long long b) : a(a), b(b){}
	long long get(long long x)
	{
		return a*x + b;
	}
};

struct lichao_tree
{
	struct node
	{
		node *l, *r;
		line x;
		node(line x) : x(x)
		{
			l = r = NULL;
		}
	};

	vector<line>vl;
	int sz = 0;
	node * root;
	void update(node *&v, long long l, long long r, line x)
	{
		if(v == nullptr)
		{
			v = new	node(x);
			return;
		}
		long long mid = (l+r) >> 1;
		bool m = bool(x.get(mid) < v->x.get(mid));
		bool le = bool(x.get(l) < v->x.get(l));

		if(m)
			swap(x, v->x);
		if(l == r)
			return;
		if(m != le)
			update(v->l,l,mid,x);
		else
			update(v->r,mid+1,r,x);
	}
	long long query(node *&v, long long k, long long l , long long r)
	{
		if(v == nullptr)
			return 1e18;
		if(l == r)
			return v->x.get(l);
		
		long long mid = (l+r) >> 1;

		if(k <= mid)
			return min(v->x.get(k), query(v->l,k,l,mid));
		else
			return min(v->x.get(k), query(v->r,k,mid+1,r));
	}
	long long query(long long p) 
	{
    	return query(root,p,-inf,inf);
  	}

  	void update(line x)
	{
		sz++;
		vl.push_back(x);
    	update(root,-inf,inf,x);
  	}
 	
	void clear() 
	{
    	root = nullptr;
  	}
};
