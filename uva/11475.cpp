#include<bits/stdc++.h>
using namespace std;
string p;
int f[100005];
string s;
void kmp_process()
{
	int i = 0;
	int j = -1;
	f[0] = -1;
	while(i < p.size())
	{
		while(j >= 0 && p[i] != p[j])
			j = f[j];
		i++;
		j++;
		f[i] = j;
	}
}
int kmp_search()
{
	int i = 0;
	int j = 0;
	while(i < s.size())
	{
		while(j >= 0 && s[i] != p[j])
			j = f[j];
		i++;
		j++;
		if(i == s.size())
			return j;
	}
}
main()
{
	ios_base::sync_with_stdio(0);
	while(cin >> s)
	{
		p = string(s.rbegin(), s.rend());	
		kmp_process();
		int aux = kmp_search();
		cout  << s + string(p.begin()+ aux,p.end()) << "\n";
	}
}
