#include<bits/stdc++.h>
using namespace std;
main()
{
	ios_base::sync_with_stdio(0);
	int test;
	cin >> test;
	int v[10];
	while(test--)
	{
		for(int i = 0; i <= 9; i++)
			v[i] = 0;
		int n;
		cin >> n;
		for(int j = 1; j <= n; j++)
		{
			int k = j;	
			while(k)
			{
				v[k%10]++;
				k /= 10;
			}
		}
		for(int i = 0; i <= 9; i++)
		{
			if(i)
				cout << ' ';
			cout << v[i];		
		}
		cout << '\n';
	}
}
