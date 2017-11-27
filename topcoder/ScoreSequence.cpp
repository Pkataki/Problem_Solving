#include <bits/stdc++.h>
using namespace std;
bool graph[102][102];
class ScoresSequence
{
	public : int count(vector<int> out)
	{
		sort(out.begin(),out.end(),greater<int>());
		vector<int>in(out.size(),0);
		int n = out.size();
        cout << n << '\n';
		for(int i = 0; i < n; i++)
		{
			in[i] = n - 1 - out[i];
			graph[i][i] = 1;
		}
		for(int i = 0; i < n; i++)
		{
			while(out[i]--)
			{
				int k = -1;
				for(int j = 0; j < n; j++)
				{
					if( i != j && !graph[i][j] && (k == -1 || in[j] >= in[k]))
						k = j;
				}
                    in[k]--;
					graph[i][k] = 1;
				
			}
		}
		for(int k = 0; k < n ; k++)
		{
			for(int i = 0; i < n ; i++)
			{
				for(int j = 0; j < n ; j++)
				{
					graph[i][j] |= graph[i][k] & graph[k][j];
				}
			}
		}
		int ans = 0;
		for(int i= 0 ; i < n ; i++)
			for(int j = 0; j < n ; j++)
				ans += graph[i][j];
		return ans;
	}
};