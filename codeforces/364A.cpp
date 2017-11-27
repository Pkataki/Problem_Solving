#include<bits/stdc++.h>
using namespace std;
int v[5000];
map<long long,int>cont;
int main()
{
	string s;
	long long a;
	cin >> a >> s;
	int n = s.size();
	for(int i = 0; i < n; i++)	
	{
		v[i] = s[i] - '0';
	}
	long long k = 0;
	
	for(int i = 0; i < n; i++)
	{
		long long aux = 0LL;
		for(int j = i; j < n; j++)
		{
			aux += v[j];
			cont[aux]++;
			k++;
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; i++)
	{
		long long sum = 0;
		for(int j = i; j < n; j++)
		{
			sum += v[j];
			if(sum != 0LL && a%sum == 0LL)
				ans += (long long)cont[a/sum];
			if(sum == 0LL && a == 0LL)
				ans += k;
		}	
	}
	cout << ans << '\n';
}
