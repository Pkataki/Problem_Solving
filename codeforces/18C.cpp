#include<bits/stdc++.h>
using namespace std;
long long p[100005];
long long suf[100005];
long long v[100005];
int main()
{
	int n;
	cin >> n;
	p[0] = 0;
	for(int i =  1; i <= n; i++)
	{
		cin >> v[i];
		p[i] = p[i-1] + v[i];
	}
	suf[n] = 0;
	for(int i = n; i >= 1; i--)
	{
		suf[i] = suf[i+1] + v[i];
	}
	int cont = 0;
	for(int i = 2; i <= n; i++)
	{
		if(p[i-1] == suf[i])
			cont++;
	}
	cout << cont << '\n';
	return 0;
}
