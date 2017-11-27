#include<bits/stdc++.h>
using namespace std;
inline int sum_digit(int n)
{
	int sum = 0;
	while(n)
	{
		sum += (n%10);
		n /= 10;
	}
	return sum;
}
inline bool solve(int n)
{
	int sum = 0;
	int ti = 0;
	int d1 = sum_digit(n);
	int ans = n;
	bool f = 0;
	for(int i = 2; i * i <= n; i++)
	{
		ti = 0;
		if(n%i == 0)
		{
			while(n%i == 0)
			{
				ti++;
				n /= i;
			}
			sum += ti*sum_digit(i);
			f = 1;
		}
	}
	if(n != 1)
		sum += sum_digit(n);

	if(d1 == sum && f)
	{
		printf("%d\n",ans);
		return 1;
	}
	return 0;
}
main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n;
		scanf("%d",&n);
		for(int i = n+1; ;i++)
		{
			if(solve(i))
			{
				break;
			}
		}
	}
}
