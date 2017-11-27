#include<bits/stdc++.h>
using namespace std;
class ILike5
{
	public : transformTheSequence(vector<int> X)
	{
		int ans = 0;
		for(int i = 0; i < X; i++)
		{
			if(X % 10 != 5)
				ans++;
		}
		return ans;
	}
};