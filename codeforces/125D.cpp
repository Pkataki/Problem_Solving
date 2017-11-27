#include<bits/stdc++.h>
using namespace std;
int v[30000];
bool check(vector<int>v)
{
	if(v.size() == 1 || v.size() == 2)
		return 1;
	if(v.size() == 0)
		return 0;
	int d = v[1] - v[0];
	for(int i = 2 ; i < v.size() ; i++)
	{
		if(v[i] - v[i-1] != d)
		{
			return false;
		}
		
	}
	return true;
}
int n;
int solve(int f, int s)
{
	int d = v[s] - v[f];
	vector<int>v1,v2;
	int next = v[f];
	int used[n];
	memset(used,0,sizeof(used));
	for(int i = 0 ; i < n; i++)
	{
		if(v[i] == next)
		{
			next += d;
			v1.push_back(v[i]);
		}
		else
			used[i] = 1;
	}
	for(int i = 0; i < n ; i++)
		if(used[i])
			v2.push_back(v[i]);

/*	cout << "test ###############\n";
	for(int i = 0; i < v1.size() ; i++)
			cout << v1[i] << ' ';
		cout << '\n';
		for(int i = 0; i < v2.size() ; i++)
			cout << v2[i] << ' ';
		cout << '\n';
	cout << "test ###############\n";
*/
	if(check(v2))
	{
		for(int i = 0; i < v1.size() ; i++)
			cout << v1[i] << ' ';
		cout << '\n';
		for(int i = 0; i < v2.size() ; i++)
			cout << v2[i] << ' ';
		cout << '\n';
		return true;
	}
//	cout << " deu ruim no primeiro check\n";
	for(int i = n-1; i >= 0; i--)
		if(v[i] == v1[v1.size()-1])
		{
			used[i] = 1;
			break;
		}
	v1.pop_back();
	v2.clear();
	for(int i = 0; i < n ; i++)
		if(used[i])
			v2.push_back(v[i]);

	if(check(v2))
	{
		for(int i = 0; i < v1.size() ; i++)
			cout << v1[i] << ' ';
		cout << '\n';
		for(int i = 0; i < v2.size() ; i++)
			cout << v2[i] << ' ';
		cout << '\n';
		return true;
	}
	return false;

}
int main()
{
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> v[i];
	}
	if(n == 2)
		cout << v[0] << '\n' << v[1] << '\n';
	else if(!solve(0,1) && !solve(1,2) && !solve(0,2) )
		cout << "No solution\n";
	return 0;
}
