#include<bits/stdc++.h>
using namespace std;
class ILike5
{
	public : int transformTheSequence(vector<int> X)
	{
		int ans = 0;
		for(int i = 0; i < X.size(); i++)
		{
            int aux = X[i] % 10;
			if(!(aux & 1))
				ans++;
		}
		return ans;
	}
};