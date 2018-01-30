#include<bits/stdc++.h>
using namespace std;
string v[100005];
int n;
string ans = "";
int m;
int cont = 0;
int idx = 0;
bool ok = 0;
void dfs()
{
	if(idx >= m)
	{
		ok = 1;
		return ;
	}
	ans += v[idx];
	idx++;
	if(v[idx - 1] == "int")
		return;
	ans += "<";
	dfs();
	ans += ',';
	dfs();
	ans += ">";
}
int main()
{
	cin >> n;
	int i;
	
	for(i = 0; cin >> v[i]; i++)
	{
		if(v[i] == "int")
			cont++;
	}
	m = i;
	if(cont != n)
	{
		cout << "Error occurred\n";
		return 0;
	}
	dfs();
	if(idx != m)
		cout << "Error occurred\n";
	else if(ok)
		cout << "Error occurred\n";
	else
		cout << ans << '\n';
	return 0;
}
