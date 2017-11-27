#include<bits/stdc++.h>
using namespace std;
char P[100];
int f[100];
int n;
int kmp_process()
{
	int i = 0, j = -1;
	f[0] = -1;
	while(i < n)
	{
		while(j >= 0 && P[i] != P[j])
			j = f[j];
		i++,j++;
		f[i] = j;
	}
	return j;
}
main()
{	
	char fim[2];
	fim[0] = '*';
	fim[1] = 0;
	while(scanf("%s",P) != EOF)
	{	
		if(!strcmp(P,fim)) break;
		n = (int)strlen(P);
		int ans = kmp_process();
		int tam = n - ans;
		printf("%d\n",n/tam);
	}
}
