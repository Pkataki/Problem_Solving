#include<bits/stdc++.h>
using namespace std;
long long s(long long num)
{
	long long sum = 0;
	while(num)
	{
		sum += (num%10LL);
		num /= 10LL;
	}
	return sum;
}
long long pot(long long a, long long b)
{
	long long sum = 1;
	for(int i = 1; i <= b; i++)
	{	
		sum *=a;
	}
	return sum;
}
int main()
{
	long long a,b,c;
	cin >> a>> b >> c;
	vector<int>ans;
	for(long long i = 1; i <= 81; i++)
	{
		long long x = b*pot(i,a) + c;
		if(s(x) == i && x < 1000000000)
		{
			ans.push_back(x);
		}
	}
	if(ans.size()  == 0)
	{
		cout << "0\n";
		return 0;
	}
	cout << ans.size() << '\n';
	cout << ans[0];
	for(int i = 1; i < ans.size(); i++)
		cout << ' ' << ans[i];
	cout << '\n';
}
