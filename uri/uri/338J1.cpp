#include<bits/stdc++.h>

using namespace std;

const int MAXN = 50;
uint64_t C[MAXN+1][MAXN+1];
uint64_t v[100];
int n,k;	
uint64_t to_bin(uint64_t x)
{
	uint64_t mask;
	uint64_t bit = (1ULL << (n-1));
	for(int i = 0; i < n; i++, bit >>= 1ULL)
	{
		if(x >= v[i])
		{
			mask |= bit;
			x -= v[i];
		}
	}
	return mask;
}
uint64_t count(uint64_t num, uint64_t k1)
{
	uint64_t ans = 0;
	uint64_t bit = (1ULL << (n-1));
	for(int i = n-1; i >= 0; i--)
	{
		if(num & bit)
		{
			if((uint64_t)i >= k1)
				ans += C[i][k1];
			k1--;
			if(k1 == 0)
			{
				ans++;
				break;
			}
		}
		bit >>= 1LL;
	}
	return ans;
}
int main()
{

  	ios::sync_with_stdio(false);

	C[0][0] = 1;
	for (int i = 1; i <= MAXN; ++i)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j)
		{
	  		C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
	}

	int test;
	cin >> test;
	while(test--)
	{
		cin >> n >> k;
		for(int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		uint64_t a,b;
		cin >> a >> b;
		
		sort(v,v+n,greater<uint64_t>());
		uint64_t t = to_bin(b);
		
		uint64_t ans = count(to_bin(b),k);
		//cout << ans <<" ***\n" << endl;
		//cout << "**\n";
		if(a)
		{
			ans -= count(to_bin(a)-1ULL,k);
			//cout << ans <<" ***\n" << endl;
		}
		cout << ans << '\n';
	}
	return 0;

}