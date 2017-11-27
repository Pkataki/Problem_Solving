#include<bits/stdc++.h>
using namespace std;

int sum_fact(int n)
{
	int sum = 0;
	for(int i = 1; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			sum += i;
			if((n / i) != i)
				sum += (n/i);
		}
	}
	return sum;
}

main()
{
	int n;
	
	vector<int>res(1001,-1);	
	for(int i = 1; i <= 1000; i++)
	{
		int ans = sum_fact(i);
		if(ans <= 1000)
			res[ans] = i;
	}
	int caso = 1;
	while(cin >> n && n)
	{
		cout << "Case " << caso << ": " << res[n] << '\n';
		caso++;
	}
}
