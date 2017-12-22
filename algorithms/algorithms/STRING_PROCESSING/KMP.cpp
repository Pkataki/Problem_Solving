#include<bits/stdc++.h>
using namespace std;
int b[10000];
char P[10000];
char T[10000];
int n,m;
void kmp_process()
{
	int i= 0, j = -1; b[0] = -1;
	while(i < m)
	{
		while(j >= 0 && P[j] != P[i])
			j = b[j];
		i++;
		j++;
		b[i] = j;
	}
}
void kmp_search()
{
	int i = 0, j = 0;
	while(i < n)
	{
		while(j >= 0 && T[i] != P[j])
			j = b[j];
		i++;
		j++;
		if(j == m)
		{
			cout << "P is found at index " << i-j << " in T\n";
		}
	}
}
main()
{
	scanf("%s",T);
	scanf("%s",P);
	n = (int)strlen(T);
	m = (int)strlen(P);
	kmp_process();
	kmp_search();
}
