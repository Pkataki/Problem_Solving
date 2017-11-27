#include<bits/stdc++.h>
using namespace std;
int p[500005];
int t[500005];
int f[500005];
int n,m;
int ans = 0;
void kmp_process()
{
	int i= 0, j = -1; f[0] = -1;
	while(i < m)
	{
		while(j >= 0 && p[i] != p[j] && (p[j] || p[i] <= j))
			j = f[j];
		i++;
		j++;
		f[i] = j;
	}
}
void kmp_search()
{
	int i = 0, j = 0;
	while(i < n)
	{
		while(j >= 0 && t[i] != p[j] && (p[j] || t[i] <= j))
			j = f[j];
		i++;
		j++;

		if(j == m)
		{
			ans++;
			j = f[j];
		}
	}
}
int last_pos[26];
main()
{
	ios_base::sync_with_stdio(0);
	for(int i = 0; i < 26; i++)
		last_pos[i] = -1;
	string s;
	cin >> s;
	n = s.size();
	for(int i = 0; s[i]; i++)
	{
		int a = s[i] - 'a';
		t[i] = (last_pos[a] == -1? 0 : i-last_pos[a]);
		last_pos[a] = i;
	}
	cin >> m;
	
	for(int i = 0; i < 26; i++)
		last_pos[i] = -1;
	
	for(int i = 0; i < m ; i++)
	{
		int num;
		cin >> num;
		num--;
		p[i] =  (last_pos[num] == -1? 0 : i - last_pos[num]);
		last_pos[num] = i;
	}
	kmp_process();
	kmp_search();
	cout << ans << "\n";
}
