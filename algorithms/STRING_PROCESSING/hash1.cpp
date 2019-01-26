
typedef unsigned long long int ull;
#define MAXN 10100
const ull A = 1009;
const ull MOD = 9ull + 1e18;
ull pot[MAXN];

ull normalize(ull r)
{
	while(r<0) r+=MOD;
	while(r>=MOD) r-=MOD;
	return r;
}

ull mul(ull a, ull b)
{
	ull q = ull((long double)a*b/MOD);
	ull r = a*b - MOD*q;
	return normalize(r);
}

ull add(ull hash, ull c)
{
	return (mul(hash, A) + c)%MOD;
}

void buildPot()
{
	pot[0] = 1ULL;
	for (int i = 1; i < MAXN; i++)
	{
		pot[i] = mul(pot[i-1], A);
	}
}

struct Hash
{
	string s;
	ull hash;
	vector<ull> h;
	
	Hash(){}
	Hash(string _s)
	{
		s = _s;
		h.resize((int)s.size()+1);
	}
	
	void build()
	{
		h[0] = 0ULL;
		for (int i = 0; i < (int)s.size(); i++)
		{
			h[i+1] = add(h[i], s[i-1]-'a'+1);
		}
		hash = h[(int)s.size()];
	}
	
	ull calc(int l, int r)
	{
		if(l>r) return 0ULL;
		ull ans = (h[r+1] - mul(h[l], pot[r-l+1]))%MOD;
		return normalize(ans);
	}
};
