#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	long long k;
	cin >> n >> k;
	if((n*(n-1))/2 > k)
	{
		int x,y;
		for(int i = 0; i < n; i++)
		{
			printf("0 %d\n",i);
		}
	}
	else
	{
		cout << "no solution\n";
	}
}
