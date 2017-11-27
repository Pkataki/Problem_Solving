#include<bits/stdc++.h>
using namespace std;
int SA[1010];
int temp[1010];
int RA[1010];
char s[1010];
int lcp[1010];
int phi[1010];
int plcp[1010];
int c[1010];
int n;
void counting(int k)
{
	memset(c,0,sizeof(c));
	int sum = 0;
int	ma = max(300,n);
	for(int i = 0; i < n; i++)
		c[SA[i] + k < n ? RA[SA[i] + k] : 0]++;
	for(int i = 0; i < ma; i++)
	{
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for(int i = 0; i < n; i++)
	{
		temp[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	}
	for(int i = 0; i < n; i++)
		SA[i] = temp[i];
}
void construct_sa()
{
	for(int i = 0; i < n; i++)
	{
		RA[i] = s[i];
		SA[i] = i;
	}
	for(int k = 1; k < n; k <<= 1)
	{
		counting(k);
		counting(0);
		temp[SA[0]] = 0;
		int r = 0;
		for(int i = 0; i < n ;i++)
			temp[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k]) ? r : ++r;
		for(int i = 0; i < n; i++)
			RA[i]= temp[i];
		if(RA[SA[n-1]] == n-1)
			break;
	}
}
void compute_lcp()
{
	phi[SA[0]] = -1;
	int l = 0;
	for(int i = 1; i < n; i++)
		phi[SA[i]] = SA[i-1];
	for(int i = 0; i < n; i++)
	{
		if(phi[i] == -1)
		{
			plcp[i] = 0;
			continue;
		}
		while(s[i+l] == s[phi[i]+l])
			l++;
		plcp[i] = l;
		l = max(0,l-1);
	}
	for(int i = 0; i < n; i++)
		lcp[i] = plcp[SA[i]];
}
main()
{
	string a,b;
	string c;
	bool pass = 0;
	while(getline(cin,a))
	{
		if(a == "\n")
			continue;
		cin >> b;
		string aux;
		if(!pass)
		{
			aux = a+b;
		}
		else
		{
			cin >> c;
			aux = b+c;
		}
		
		n = (int)aux.size();
		int h;
		
		for(h = 0; h < aux.size(); h++)
			s[h] = aux[h];
		
		s[h] = 0;
		construct_sa();
		compute_lcp();

		int ma = 0;
		for(int i = 0; i < n; i++)
		{
			if(lcp[i] > ma)
			{
				ma = lcp[i];
			}
		}
		for(int i = 0; i < n; i++)
		{
			if(lcp[i] == ma)
			{
				for(int j = SA[i]; j < SA[i] + lcp[i]; j++)
				{
					cout << s[j];
				}
				cout << "\n";
			}
		}
		if(pass)
			cout << "\n";
		pass = 1;
	}
}
