#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,b;
	cin>> n >> a >> b;
	if(a+b > n)
		cout << "Deixa para amanha!\n";
	else
		cout << "Farei hoje!\n";
	return 0;
}
