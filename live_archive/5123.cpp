#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n;
ull pot10[9];

int cont[10];
int solve(int last, int pos)
{
	
}
int main()
{
	pot10[0] = 1;
	for(int i = 1; i <= 9; i++)
		pot10[i] = pot10[i-1] * 10;

	
	while(scanf("%lld",&n) == 1)
	{
		memset(cont,0,sizeof(cont));
		ull aux = n;
		while(aux)
		{	
			cont[aux%10]++;
			aux /= 10;
		}

	}
}
