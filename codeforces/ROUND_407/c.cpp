#include<bits/stdc++.h>
using namespace std;
map<long long,bool>mapa;
long long _abs(long long a)
{
	if(a >= 0)
		return a;
	else
		return -a;
}
int main()
{
	long long b1,q,l,m;
	cin >> b1 >> q >> l >> m;
	for(int i = 0; i < m; i++)
	{
		long long a;
		cin >> a;
		mapa[a] = 1;
	}
	if(b1 == 0LL)
	{
		if(!mapa.count(0))
			cout << "inf\n";
		else
			cout << "0\n";
		return 0;
	}

	if(q == 0LL)
	{
		if(_abs(b1) > l)
			cout << "0\n";
		else if(!mapa.count(0))
			cout << "inf\n";
		else if(!mapa.count(b1))
			cout << "1\n";
		else
			cout << "0\n";
		return 0;
	}
	else if(q == 1LL)
	{
		if(_abs(b1) <= l && !mapa.count(b1))
			cout << "inf\n";
		else
			cout << "0\n";
		return 0;
	}
	else if(q == -1LL)
	{
		if(_abs(b1) > l)
			cout << "0\n";
		else if( !mapa.count(b1) || !mapa.count(-b1) )
			cout << "inf\n";
		else
			cout << "0\n";
		return 0;
	}
	long long val = b1;
	int cont = 0;
	while(_abs(val) <= l)
	{
		if(!mapa.count(val))
			cont++;
		val *= q;
	}
	cout << cont << '\n';

}
