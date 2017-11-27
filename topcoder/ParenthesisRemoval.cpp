#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
class ParenthesisRemoval
{
	public: int countWays(string s)
	{
		long long ans = 1;
		long long open = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '(')
				open++;
			else
			{
				ans = (ans * open) % MOD;
				open--;
			}
		}
		return (int)ans;
	}
};
int main()
{
	ParenthesisRemoval test;
	cout << test.countWays("()()()()()") << "\n";
	return 0;
}