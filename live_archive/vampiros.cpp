#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull pot[19];
ull ori;
int cont[10];
int n;
bool solve(int pos , int last, int last2, ull sum , ull sum2)
{
	if((pos >= (int)(n >> 1)))
	{
		
		return  ((last != 0) && (last2 != 0) && (sum * sum2 == ori));
	}
	for(ull i = 0 ; i < 10; i++)
	{
		if(cont[i] <= 0 || (last == 0 && i == 0))
			continue;
		for(ull j = 0; j < 10; j++)
		{
			if(cont[j] <= 0 || (last2 == 0 && j == 0))
				continue;
			ull aux = sum + pot[pos] * (ull)i;
			
			ull aux2 = sum2 + pot[pos] * (ull)j;
			cont[i]--;
			cont[j]--;
			int a = 0;
			
			if(((aux * aux2) % pot[pos +1]) == (ori % pot[pos+1]))
				a = solve(pos+1, i, j, aux, aux2);
			
			if(a)
				return true;
			cont[i]++;
			cont[j]++;
		}
	}
	return false;
	 
}
int main()
{
	__int128 a = 5;
	ios_base::sync_with_stdio(0);
	
	pot[0] = 1;
	for(int i = 1; i < 19; i++)
		pot[i] = pot[i-1] * 10ULL;
	
	while(cin >> ori && ori)
	{
		memset(cont,0,sizeof(cont));	
		ull aux = ori;
		while(aux)
		{
			cont[aux % 10]++;
			aux /= 10;
		}
		n = log10(ori) + 1;
		cout << ori << ": ";
		if(solve(0,-1,-1,0,0))
			cout << "yes\n";
		else
			cout << "no\n";
	}
}
