#include<bits/stdc++.h>
using namespace std;
/* Encontrar palindromos - inicializa d1 e d2 com zeros, e eles guadram 
 * o numero de palindromos centrados na posicao i (d1[i] e d2[i])*/
/* impar */
 
 
int main()
{
	int n;
	string s;
	int test;
	cin >> test;
	while(test--)
	{
		cin >> s;
		n = s.size();
		vector<int>f(5*n,0);
		vector<int> d1 (n+5,0);
		int l = 0, r = -1;
		for (int i=0; i<n; ++i)
		{
		    int k = (i > r ? 0 : min (d1[l+r-i], r-i)) + 1;
		    while (i+k < n && i-k >= 0 && s[i+k] == s[i-k]) 
		    {	
		    	++k;
		    }
		    d1[i] = --k;
		    if (i+k > r)
		    {
		    	f[2*k+1]++;
		        l = i-k,  r = i+k;
		    }
		}
		/* par */
		vector<int> d2 (n+5,0);
		l = 0, r = -1;
		for (int i=0; i<n; ++i)
		{
		    int k = (i>r ? 0 : min (d2[l+r-i+1], r-i+1)) + 1;
		    while (i+k-1 < n && i-k >= 0 && s[i+k-1] == s[i-k])
		    {	
		    	++k;
		    }
		    d2[i] = --k;
		    if (i+k-1 > r)
		    {
		    	 f[2*k]++;
		   
		        l = i-k,  r = i+k-1;
		    }
		}
		bool ok  = 0;
		for(int i = n; i >= 2; i--)
		{
			if(f[i])
			{
				ok = 1;
				cout << i << ' ' << f[i] << '\n';
				break;
			}
		}
		if(!ok)
			cout << 1 << ' ' << n << '\n';
	}
	return 0;
} 