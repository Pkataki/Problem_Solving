#include<bits/stdc++.h>
using namespace std;
int v[10005];
int main()
{
	int n;
	cin >> n;
	int cont = 1;
	for(int i = 0; i < n ; i += 2)
		v[i] = cont++;
	cont = n;
	for(int i = 1; i < n ; i += 2)
		v[i] = cont--;
	for(int i = 0; i < n ; i++)
		cout << v[i] << ' ';
	cout << '\n';
	return 0;
}
