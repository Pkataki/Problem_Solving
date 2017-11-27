#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ans= 0;
	for(int c = 0; c < 2 ; c++)
	{
		int bad = 0;
		for(int j = 0, i=0; j < n; j++)
		{
			if(s[j] - 'a' != c)
				bad++;
			if(bad > k)
			{
				while(i <= j && s[i] - 'a' == c)
					i++;
				i++;
				bad--;
			}
			ans = max(ans, j-i+1);
		}
	}
	cout << ans << '\n';
	return 0;
}
