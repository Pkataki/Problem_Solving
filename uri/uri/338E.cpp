#include<bits/stdc++.h>
using namespace std;
int main()
{
	string v[] = {"Rudolph","Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen"};
	int sum = 0;
	for(int i = 0; i < 9; i++)
	{
		int a;
		cin >> a;
		sum += a;
	}
	cout << v[sum%9] << '\n';
	return 0;
}
