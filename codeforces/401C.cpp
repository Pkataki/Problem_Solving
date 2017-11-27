#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	if(n > 2*m || m < 2*n)
		cout << "-1\n";
	else
	{
		while(n-1 >= 0 && m-2 >= 0)
		{
			cout << "110";
			n--;
			m-=2;
		}
		
		while(n -1  >= 0 || m-1 >= 0)
		{
			if(n-1 >= 0)
			{
				n--;
				cout << 0;
			}
			if(m-1 >= 0)
			{
				m--;
				cout << 1;
			}
		}
		cout << '\n';
	}
	return 0;
}
