#include<bits/stdc++.h>
using namespace std;
// rgd mapeia a diagonal a direita
// lfd mapeia a diagonal a esquerda
// c coluna 
// l linha
char mat[16][16];
int cont;
int n;
void solve(int l, int c, int rgd,int lfd)
{
	if(l == n)
	{
		cont++;
		return;
	}
	int state = c | lfd | rgd;
	for(int i = 0; i < n; i++)
	{
		if(!(state & (1 << i)) && mat[l][i] == '.')
			solve(l+1, (c |( 1 << i)) , ((rgd | (1 << i)) >> 1), ((lfd |(1 << i)) << 1));
	}
}
main()
{
	ios_base::sync_with_stdio(0);
	int test = 1;
	while(cin >> n && n)
	{
		cont = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> mat[i][j];
		
		solve(0,0,0,0);
		cout <<"Case " <<  test <<": " << cont << "\n";
		test++;
	}

}
