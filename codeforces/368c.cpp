#include<bits/stdc++.h>
using namespace std;
main()
{
	long long n;
	cin >> n;
	long long x;
	for(int i = 1; i <= 90; i++)
	{
		double aux = ((double)i * M_PI)	/180.0;
		double angle = sin(aux);
		long long hip = ceil(n / angle);
		long long cat = n*n * sin(aux);
		cout << hip << " " << cat << "\n";
		
		if(hip*hip == (cat*cat + n*n) && hip && cat)
		{
			break;
		}
	}
}
