#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(NULL));
	cout << 50 << ' '<< 23 << '\n';
	for(int i = 0; i < 50; i++)
	{
		cout <<  (long long)rand()*i << ' ';
	}
	cout <<  (long long)rand() << ' ' <<   (long long)rand() << '\n';

	return 0;
}
