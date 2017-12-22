#include<bits/stdc++.h>
using namespace std;

struct complex_t {
  double a {0.0}, b {0.0};
  complex_t() {}
  complex_t(double na, double nb) : a{na}, b{nb} {}
  const complex_t operator+(const complex_t &c) const {
    return complex_t(a + c.a, b + c.b);
  }
  const complex_t operator-(const complex_t &c) const {
    return complex_t(a - c.a, b - c.b);
  }
  const complex_t operator*(const complex_t &c) const {
    return complex_t(a*c.a - b*c.b, a*c.b + b*c.a);
  }
};

using base = complex_t;

void fft (vector<base> & a, bool invert) 
{
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) 
	{
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) 
	{
		double ang = 2*M_PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w =  complex_t(1.0, 0.0);
			for (int j = 0; j < len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w = w * wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i].a /= n, a[i].b /= n;
}
int sum[300005];
vector<base>fa(3000005);
vector<base>fb(3000005);

int main()
{
	ios_base::sync_with_stdio(0);
	string s; 
	cin >> s;
	int ac=0;
	fa[0] = complex_t(1.0, 0.0);
	for(int i = 0 ; i < s.size() ; i++)
	{
		ac += ((s[i] - 'a') + 1);
		sum[i] = ac;

	}	
	for(int i = 0 ; i < s.size(); i++)
	{
		fa[sum[i]] = complex_t(1.0, 0.0);
	}
	fb[0] = complex_t(1.0, 0.0);
	fb[ac] = complex_t(1.0, 0.0);
	for(int i = 0 ; i < s.size(); i++)
	{
		fb[ac - sum[i]] = complex_t(1.0, 0.0);
	}
	int n = 1;
	while(n < ac) n <<= 1;
	n <<= 1;
	fa.resize(n);
	fb.resize(n);	
	fft(fa,0);
	
	fft(fb,0);
	for(int i = 0 ; i <= n; i++)
	{
		fa[i] = fa[i]*fb[i];
	}
	fft(fa,1);
	int ans = 0;
	for(int i = 1; i <= ac; i++)
	{
		if(int(fa[i].a + 0.5))
		{
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
