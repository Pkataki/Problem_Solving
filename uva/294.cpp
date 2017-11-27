#include<bits/stdc++.h>
using namespace std;
int num_divs(int num)
{
	int ans = 1;
	for(int i = 2; i * i <= num; i++)
	{
		int power = 0;
		while(num %i == 0)
		{
			num /= i;
			power++;
		}
		ans *= (power + 1);
	}
	if(num > 1)
	{
		ans *= 2;
	}
	return ans;
}
main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int l,u;
		cin >> l >> u;
		int ans = 0;
		int ans1 = 0;
		for(int num = l; num <= u; num++)
		{
			int aux = num_divs(num);
			if(aux > ans)
			{
				ans = aux;	
				ans1 = num;
			}
		}
		cout << "Between " << l << " and " << u << ", " <<  ans1 <<" has a maximum of " <<  ans  << " divisors.\n";
	}
}
