#include<bits/stdc++.h>
using namespace std;
int v[30005];
int bit[190][30005];

void update(int bl, int idx, int val)
{
	while(idx )
	{
		bit[bl][idx] += val;
		idx -= idx & (-idx);
	}
}
int query(int bl, int idx)
{
	int ans = 0;
	while( idx <= 30005)
	{
		ans += bit[bl][idx];
		idx += idx & (-idx);
	}
	return ans;
}


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

int main()
{
	int n,q;
	read(n);
	int len = ceil(sqrt(n))+1 ;
	for(int i = 1; i <= n ; i++)
	{
		read(v[i]);
		update(i/len, v[i], 1);
	}
	read(q);
	while(q--)
	{
		int op;
		read(op);
		if(op == 1)
		{
			int a,b,c;
			read(a);
			read(b);
			read(c);
			int ans = 0;
			while( a % len != 0 && a <= b)
				ans += (v[a++] > c);
			while( b % len != (len-1) && a <= b)
				ans += (v[b--] > c);
			if(b > a)
			{
				int l = a/len;
				int r = b /len;
				for(int i = l ; i <= r; i++)
				{
					ans += query(i, c+1);
				}
			}
			writeInt(ans);
			putchar_unlocked('\n');
		}
		else
		{
			int a,b;
			read(a);
			read(b);
			int k = a/len;
			update(k, v[a], -1);
			update(k, b, 1);
			v[a] = b;
		}
	}
	return 0;
}
