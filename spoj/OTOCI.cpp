#include<bits/stdc++.h>
using namespace std;
template <class _T> inline void read(_T &_x) {
	int _t; bool _flag=false;
	while((_t=getchar())!='-'&&(_t<'0'||_t>'9')) ;
	if(_t=='-') _flag=true,_t=getchar(); _x=_t-'0';
	while((_t=getchar())>='0'&&_t<='9') _x=_x*10+_t-'0';
	if(_flag) _x=-_x;
}
typedef long long LL;
const int maxn = 400010;
int n, m, q, u0[maxn], v0[maxn];
int f[maxn], ch[maxn][2], mn[maxn], rev[maxn];
int sum[maxn];
inline bool isroot(int c) {
	return ch[f[c]][0] != c && ch[f[c]][1] != c;
}
inline void re(int c) {
	swap(ch[c][0], ch[c][1]), rev[c] ^= 1;
}

inline void pushup(int c) {
	sum[c] = mn[c];
	if (ch[c][0]) sum[c] += sum[ch[c][0]];
	if (ch[c][1]) sum[c] += sum[ch[c][1]];
}
inline void pushdown(int c) {
	if (rev[c]) {
		re(ch[c][0]), re(ch[c][1]);
		rev[c] = 0;
	}
}
inline void pushpath(int c) {
	static int st[maxn], top;
	st[top = 1] = c;
	while (!isroot(c)) st[++top] = c = f[c];
	while (top) pushdown(st[top--]);
}
inline void rotate(int c) {
	int b = f[c], a = f[b], x = ch[b][1] == c;
	if (!isroot(b)) ch[a][ch[a][1] == b] = c;
	ch[b][x] = ch[c][x ^ 1], f[ch[b][x]] = b;
	ch[c][x ^ 1] = b, f[b] = c, f[c] = a;
	pushup(b);
}
inline void splay(int c) {
	pushpath(c);
	for (int b; !isroot(c); rotate(c)) if (!isroot(b = f[c]))
		rotate((ch[f[b]][1] == b) == (ch[b][1] == c) ? b : c);
	pushup(c);
}
inline void access(int c) {
	for (int b = 0; c; b = c, c = f[c])
		splay(c), ch[c][1] = b, pushup(c);
}
inline void makeroot(int c) {
	access(c), splay(c), re(c);
}
inline void link(int a, int b) {
	makeroot(a), f[a] = b;
}
inline void cut(int a, int b) {
	makeroot(a), access(b), splay(b);
	ch[b][0] = f[a] = 0, pushup(b);
}
inline bool sametree(int a, int b) {
	makeroot(a), access(b), splay(b);
	while (ch[b][0]) b = ch[b][0], pushdown(b);
	return a == b;
}
inline int query(int a, int b) {
	if(!sametree(a,b))
		return -1;
	return sum[b];
}
inline void update(int c, int val)
{
	makeroot(c);
	mn[c] = val;
	pushup(c);
}
int main()
{
	ios::sync_with_stdio(0);
	int n,m;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 1; i <= n; i++)
		{
			int a,b;
			read(mn[i]);
			sum[i] = mn[i];
		}
		scanf("%d",&m);
		while(m--)
		{
			int x,y;
			char op[55];
			scanf("%s",op);
			read(x);
			read(y);
			if(op[0] == 'b')
			{
				if(sametree(x, y))
					puts("no");
				else
				{
					link(x,y);
					puts("yes");
				}
			}
			else if(op[0] == 'p')
			{
				update(x, y);
			}
			else
			{
				int ans = query(x, y);
				if (ans == -1)
					puts("impossible");
				else
					printf("%d\n", ans);
			}
		}
	}
	return 0;
}