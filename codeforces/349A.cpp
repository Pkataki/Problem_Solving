#include<bits/stdc++.h>
using namespace std;
map<int,int>troco;
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if(!i && a != 25)
		{
			cout << "NO\n";
			return 0;
		}
		if(a == 25)
		{
			troco[a]++;
		}
		else if(a == 50)
		{
			if(troco[25] == 0)
			{
				cout << "NO\n";		
				return 0;
			}
			else
			{
				troco[50]++;
				troco[25]--;
			}
		}
		else
		{
			if(troco[50] > 0 && troco[25] > 0)
			{
				troco[50]--;
				troco[25]--;
			}
			else if(troco[25] >= 3)
			{
				troco[25] -= 3;
			}
			else
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	
}
