#include<bits/stdc++.h>
using namespace std;
string v[100005];
int n;
int c[100005];
string ans = "";
void dfs(int last, int i)
{
	if(i == n)
		return;
	if(v[i] == "int")
	{
		c[last]++;
		ans += "int";
		return;
	}
	if(v[i] == "pair")
	{
		c[last]++;
		ans += v[i] + "<";
		dfs(i,i+1);
		ans += ",";
		dfs(i,i+2);
	}
	ans += ">";
}
int main()
{
	cin >> n;
	int cont = 0;
	int i;
	for(i = 0; cin >> v[i]; i++)
	{
		if(v[i] == "int")
			cont++;
	}
	if(cont != n)
	{
		cout << "Error occurred\n";
		return 0;
	}
	dfs(0,0);
	bool ok = 1;
	for(int j = 0 ;j < i ; j++)
	{
		cout << j << ' ' << c[j] << " **\n";
		if(c[j] != 2)
		{
			ok = 0;
			cout << "Error occurred\n";
		}
	}
	if(ok)
		cout << ans << '\n';
	return 0;
}
