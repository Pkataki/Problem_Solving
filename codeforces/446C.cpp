#include<bits/stdc++.h>
using namespace std;
vector<int>block[600];
int v[300005];
int posb[300005];
const int MOD = (int)1e9 + 7;
int fib[300005];
int pref[300005];
int acm[600];
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	int len = sqrt(n);
	fib[0] = pref[0] = 1;
	fib[1] =  1;
	pref[1] += pref[0];

	for(int i = 2; i <= n ; i++)
	{
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
		pref[i] = (pref[i-1] + fib[i]) % MOD;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		block[i/len].push_back(v[i]);
		acm[i/len] += v[i];
		posb[i] = i/len;
	}
	while(m--)
	{
		int op,l,r;
		cin >> op >> l >> r;
		l--;
		r--;
		if(op == 1)
		{
			int k = l % len;
			int idx = 0;
			int al = l;
//			cout << "kl: " << k << endl;
			for(int i = k; i < len && l <= r; i++)
			{
				v[l++] += fib[idx++];
				v[l-1] %= MOD;
				acm[posb[al]] += fib[idx-1];
				acm[posb[al]] %= MOD;
			}
//			cout << "depois: " << l << ' ' << r << endl;
			if(l >= r)
				continue;
//			cout << "al: " << posb[al] << ' ' << acm[posb[al]]  << " **\n"; 
			k = r % len;
			int ar = r;
//			cout << "kr: " << k  << " idx: " << idx << endl;
			int id = idx;
			idx += k * ( posb[ar] - posb[al] );
//			cout << idx << " **\n";
			for(int i = k; i >= 0  && r >= al; i--)
			{
				v[r--] += fib[idx--];
				v[r+1] %= MOD;
				acm[posb[ar]] += fib[idx+1];
				acm[posb[ar]] %= MOD;
			}
//			cout <<"ar: " << posb[ar] << ' ' << acm[posb[ar]]  << " **\n"; 
			
			if(r > l)
			{
				idx = id;
				for(int i = posb[al] + 1; i <= posb[ar] - 1; i++)
				{
					acm[i] += (pref[len + idx] - pref[idx-1]) % MOD;
					idx += len;
				}
//				cout << idx-1<< " --> " << len+idx  << " **\n"; 
			}
		
/*			cout << "array: " << endl;

			for(int i = 0; i < n ; i++)
			{
				cout << i << ' ' << v[i] << '\n';
			}
*/		}
		else
		{
			int k = l % len;
			int al = l;
			int ar = r;
			int ans = 0;
			for(int i = k; i < len && l <= r; i++)
			{
				ans += v[l++];
				ans %= MOD;
			}
			if(l >= r)
				continue;
			k = r % len;
			for(int i = k; i >= 0  && r >= al; i--)
			{
				ans += v[r--];
				ans %= MOD;
			}
			if(r > l)
			{
				for(int i = posb[al]+1; i <= posb[ar]-1; i++)
				{
					ans += acm[i];
					ans %= MOD;
				}
			}
			cout << ans << '\n';
/*			cout << "array: \n";
			for(int i = 0; i < n ; i++)
			{
				cout << i << ' ' << v[i] << '\n';
			}
*/		}
	}
	return 0;
}
