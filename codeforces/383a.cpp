#include<bits/stdc++.h>
using namespace std;

main()
{
	int n;
	cin >> n;
	int aux = n % 4;
	if(n == 0)
		cout << 1 << endl;
	else if(aux == 1)
		cout << 8 << endl;
	else if(aux == 2)
		cout << 4 << endl;
	else if(aux == 3)
		cout << 2 << endl;
	else if(aux == 4)
		cout << 6 << endl;
	else if(aux == 0)
		cout << 6 << endl;
}
