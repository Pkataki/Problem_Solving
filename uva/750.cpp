#include<bits/stdc++.h>
using namespace std;
int lin,col;
bool mat[9][9];
vector<string>ans;
bool can_place(int lin,int col)
{
	for(int i = lin, j = col; i >= 0 && j < 8; i--,j++)
	{
		if(mat[i][j])
			return false;
	}
	for(int i = lin, j = col; i < 8 && j < 8; i++,j++)
	{
		if(mat[i][j])
			return false;
	}
	for(int i = lin, j = col; i < 8 && j >= 0; i++,j--)
	{
		if(mat[i][j])
			return false;
	}
	for(int i = lin, j = col; i >= 0 && j >= 0; i--,j--)
		if(mat[i][j])
			return false;
	for(int i = 0; i < 8; i++)
		if(mat[i][col])
			return false;
	for(int i = 0; i < 8; i++)
		if(mat[lin][i])
			return false;
	return true;
}
void solve(int c,int q, string aux)
{
	if(q == 8)
	{
		ans.push_back(aux);
	}
	if(c == col-1)
	{
		solve(c+1,q+1,aux+to_string(lin));
	}
	bool ok = 0;
	for(int i = 0; i < 8; i++)
	{
		if(i != lin-1)
		{
			if(can_place(i,c))
			{
				ok = 1;
				mat[i][c] = 1;
				solve(c+1,q+1,aux+to_string(i+1));
				mat[i][c] = 0;
			}
		}
	}
}
main()
{
	int test;
	cin >> test;
	while(test--)
	{
		ans.clear();
		memset(mat,0,sizeof(mat));
		cin >> lin >> col;	
		mat[lin-1][col-1] = 1;
		solve(0,0,"");
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");;
		for(int i = 0; i < ans.size(); i++)
		{
			if(i < 9)
			cout << " ";
			cout << i+1 << "      ";
			for(int j = 0; j < ans[i].size(); j++)
			{
				if(j)
					cout << " ";
				if(ans[i][j] >= '0' && ans[i][j] <= '9')
					cout << ans[i][j];
			}
			cout << "\n";
		}
		if(test)
			cout << "\n";
	}
}
