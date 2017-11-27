#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int v[n];
	int v1[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&v[i]);
		v1[i] = v[i];
	}
	sort(v1,v1+n);
	int cont = 0;
	for(int i = 0; i < n; i++)
	{
		if(v[i] != v1[i])
			cont++;
	}
	if(cont > 2)
		cout << "NO\n";
	else
		cout << "YES\n";
}	
