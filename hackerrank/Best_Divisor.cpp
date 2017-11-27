#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int best;
	int bigger = 0;
	for(int i = 1; i <= (int)sqrt(n); i++)
	{
		if(n % i == 0)
		{
			int aux = i;
			int sum = 0;
			while(aux)
			{
				sum += (aux % 10);	
				aux /= 10;
			}
			if(sum > bigger)
			{
				best = i;
				bigger = sum;
			}
			aux = n/i;
			sum = 0;
			while(aux)
			{
				sum += (aux % 10);	
				aux /= 10;
			}
			if(sum > bigger)
			{
				best = n/i;
				bigger = sum;
			}
		}
	}
	cout << best << "\n";
	return 0;
}
