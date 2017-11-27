#include <bits/stdc++.h>
using namespace std;
int mat[2000][2000];
int main()
{
	int n,k,d;
	cin >> n >> k >> d;
	long long val = 1LL;
	bool ok = 0;
	for(int i = 0; i < d; i++)
	{
		val *= k;
		if(val >= n)
		{
			ok = 1;
			break;
		}
	}
	if(!ok)
	{
		cout << "-1\n";
		return 0;
	}
	for(int i = 0 ; i < n ; i++)
	{
		int aux = i;
		for(int j = 0; j < d; j++)
		{
			mat[i][j] = aux%k + 1;
			aux /= k;
		}
	}
	for(int i = 0 ; i < d; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			cout << mat[j][i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
