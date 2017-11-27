#include<bits/stdc++.h>
using namespace std;
class ConsecutiveOnes
{
	public : long long get(long long n, int k)
	{
		long long ans = (1LL << 60);
		for(int i = 0 ; i < 50 ; i++)
		{
			if(i + k > 50)
				break;
			long long aux = (1LL << (i + k)) - (1LL << i);
			if((n & aux) == aux)
				ans = min(ans,n);
			else
			{
				ans = min(ans, (n | aux) & ~((1LL << i)-1));
			}
		}
		return ans;
	} 
};