#include<bits/stdc++.h>
using namespace std;
map<char,long long>mapa;
long long need[3];
long long p[3];
long long n[3];
long long f(long long x)
{
	return max(0LL,need[0]*x - n[0])*p[0] + max(0LL, need[1]*x - n[1])*p[1] + max(0LL, need[2]*x - n[2])*p[2];
}
int main()
{
	mapa['B'] = 0;
	mapa['S'] = 1;
	mapa['C'] = 2;
	string s;
	cin >> s;
	for(int i = 0; i < 3; i++)
		cin >> n[i];
	for(int i = 0; i < 3; i++)
		cin >> p[i];
	long long r;
	cin >> r;
	for(int i = 0; i < s.size(); i++)
	{
		need[mapa[s[i]]]++;
	}
	long long lo = 0;
	long long hi = 1e13;
	while(lo <= hi)
	{
		long long mid = (lo + hi) >> 1;
		if(f(mid) > r)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	cout << hi << '\n';
}
