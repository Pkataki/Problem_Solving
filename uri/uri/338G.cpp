#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		int a = 0;
		int b = 0;
		int n;
		cin >> n;
		bool ok = 1;
		for(int i = 0 ; i < n ; i++)
		{
			int c;
			cin >> c;
			if(abs(a+c - b) <= 5)
				a+=c;
			else if(abs(b+c - a) <= 5)
				b += c;
			else
			{
				ok = 0;
			}
		}
		if(ok)
			cout << "Feliz Natal!\n";
		else
			cout << "Ho Ho Ho!\n";
	}
	return 0;
}
