#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

bool read( int &n ) { 
    n = 0; 
    register bool neg = false; 
    register char c = getchar_unlocked(); 
    if( c == EOF) { n = -1; return false; } 
    while (!('0' <= c && c <= '9')) { 
        if( c == '-' ) neg = true; 
        c = getchar_unlocked(); 
    } 
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar_unlocked(); 
    } 
    n = (neg ? (-n) : (n)); 
    return true; 
} 
 
inline void writeInt(int n){ 
    register int idx = 20; 
    if( n < 0 ) putchar_unlocked('-'); 
    n = abs(n); 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
} 

class link_cut_tree
{
	int left[MAXN];
	int right[MAXN];
	int parent[MAXN];
	
	public : void init(int n) 
	{
		for(int i = 0; i <= n ; i++)
		{
			left[i] = 0;
			parent[i] = 0;
			right[i] = 0;
		}
	}

	bool isRoot(int x) {
		return (parent[x] == 0 || (left[parent[x]] != x && right[parent[x]] != x));
	}

	void connect(int ch, int p, bool leftChild) {
		if (leftChild)
			left[p] = ch;
		else
			right[p] = ch;
		if (ch != 0)
			parent[ch] = p;
	}

	void rotate(int x) {
		int p = parent[x];
		int g = parent[p];
		bool isRootP = isRoot(p);
		bool leftChildX = (x == left[p]);

		connect(leftChildX ? right[x] : left[x], p, leftChildX);
		connect(p, x, !leftChildX);

		if (!isRootP)
			connect(x, g, p == left[g]);
		else
			parent[x] = g;
	}

	void splay(int x) {
		while (!isRoot(x)) {
			int p = parent[x];
			int g = parent[p];
			if (isRoot(p)) 
			{
				rotate(x);
			} 
			else if ((x == left[p]) == (p == left[g])) 
			{
				rotate(p);
				rotate(x);
			} 
			else 
			{
				rotate(x);
				rotate(x);
			}
		}
	}

	int expose(int x) {
		int last = 0;
		for (int y = x; y != 0; y = parent[y]) {
			splay(y);
			left[y] = last;
			last = y;
		}
		splay(x);
		return last;
	}

	int findRoot(int x) {
		expose(x);
		while (right[x] != 0)
			x = right[x];
		return x;
	}

	// prerequisite: x is a root node, y is in another tree
	public : bool link(int x, int y) {
		expose(x);
		if (right[x] != 0)
			return false;
		parent[x] = y;
		return true;
	}

	public : bool cut(int x) 
	{
		expose(x);
		if (right[x] == 0)
			return false;
		parent[right[x]] = 0;
		right[x] = 0;
		return true;
	}

	public : int lca(int x, int y) 
	{
		if (findRoot(x) != findRoot(y))
			return 0;
		expose(x);
		return expose(y);
	}
};
int main()
{
	link_cut_tree lk;
	int n,k;
	read(n);
	read(k);
	lk.init(n+1);
	while(k--)
	{
		string s;
		char c = getchar_unlocked();
		while(c != ' ' && c != '\n')
		{
			s += c;
			c = getchar_unlocked();
		}

		if(s == "lca")
		{
			int a,b;
			read(a);
			read(b);
			int LCA = lk.lca(a,b);
			writeInt(LCA);
			putchar_unlocked('\n');
		}
		else if(s[0] == 'c')
		{
			int a;
			read(a);
			lk.cut(a);
		}
		else
		{
			int a,b;
			read(a);
			read(b);
			lk.link(a,b);
		}
	}
	return 0;
}	
