#include <bits/stdc++.h>
using namespace std;
class RememberWords
{
	public : string isPossible(int d1, int d2, int w1, int w2)
	{
		int last = 0;
		int last1 = 0;
		bool ok = 0;
		if((w1 % d1) != 0)
		{
			last = w1/d1;
			ok = 1;
		}
		else
		{
			last = w1/d1;
		}
		bool ok1 = 0;
		if((w2 % d2) != 0)
		{
			last1 = w2/d2;
			ok1 = 1;
		}
		else
		{
			last1 = w2/d2;
		}
		int val = abs(last - last1);
		if( val <= 3)
		{
			if((ok && !ok1) || (!ok && ok))
			{
				if(val <= 3)
					return "Possible";
				else
					return "Impossible";
			}
			if(ok && ok1)
			{
				if(val <= 3)
					return "Possible";
				else
					return "Impossible";
			}
			if(!ok && !ok1)
			{
				if(val <= 1)
					return "Possible";
				else
					return "Impossible";
			}
		}
		else
			return "Impossible";
		return "Possible";
	}
};
int main()
{
	RememberWords ans;
	cout << ans.isPossible(2,3,7,18) << '\n';
	return 0;
}