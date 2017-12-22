#include <bits/stdc++.h>

using namespace std;

string nome[40];
string art[40];
int idx[40];
int ans;
int custo_nome[(1<<6)][32];
int custo_art[(1<<6)][32];

unordered_map < string, int > sub_all;
unordered_set < string > sub_nome[40];
unordered_set < string > sub_art[40];
int n, m;


void solve( int at, int qt, int mask, int used){
	if( qt < 0 )
		return ;

	if( at >= n )
	{
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			int custo = 0;
			if( used & (1 << i) )
				custo = min(custo_nome[mask][i], custo_art[mask][idx[i]]);
			else 
				custo = custo_nome[mask][i];
			if( custo >= 1e9 ) 
				return ;
			sum += custo;
		}
		ans = min(ans, sum);
		return ;
	}
	
	if( qt < 0 ) return ;

	if( !(mask & (1 << idx[at])) )
	{
		solve(at+1, qt-1 , mask | (1<<(idx[at])) , used | (1 << at));
	}
	
	solve(at+1, qt, mask, used);
	
}


int main(){
	ios::sync_with_stdio(0);

	while( cin >> n && n )
	{

		map < string, int > qt;
		vector < string > art_o;

		for(int i = 0, w = 0; i < n; i++)
		{
			cin >> nome[i] >> art[i];
			if( qt.count(art[i]) == 0 ){
				qt[art[i]] = w++;
				art_o.push_back(art[i]);
			}
			idx[i] = qt[art[i]];
		}

		sub_all.clear();
		m = qt.size();

		for(int i = 0; i < n; i++)
		{
			sub_nome[i].clear();
			for(int j = 0; j < nome[i].size(); j++)
			{
				string st = "";
				
				for(int k = j; k < nome[i].size(); k++)
				{
					st += nome[i][k];

					if( !sub_nome[i].count(st) )
						sub_all[st]++;

					sub_nome[i].insert(st);
					
				}
			}
		}


		for(int mask = 0; mask < (1 << m); mask++)
		{
			vector < int > at;
			for(int j = 0; j < m; j++)
			{
				if( mask & (1 << j) ) at.push_back(j);
				custo_art[mask][j] = 1e9;
			}

			for(int i = 0; i < n; i++) custo_nome[mask][i] = 1e9;
			
			unordered_map < string, int > aux = sub_all;
			
			for(int w = 0; w < at.size(); w++)
			{
				int i = at[w];
				sub_art[i].clear();
				for(int j = 0; j < art_o[i].size(); j++)
				{
					string st = "";
					for(int k = j; k < art_o[i].size(); k++)
					{
						st += art_o[i][k];
						
						if( !sub_art[i].count(st) )
						{
							sub_all[st]++;
						}
						sub_art[i].insert(st);
					}
				}
			}

			for(int w = 0; w < at.size(); w++)
			{
				int i = at[w];
				for(int j = 0; j < art_o[i].size(); j++)
				{
					string st = "";
					for(int k = j; k < art_o[i].size(); k++)
					{
						st += art_o[i][k];
						if( (sub_all[st]-1) == 0 )
						{
							custo_art[mask][i] = min(custo_art[mask][i], (int)st.size());
						}
					}
				}
			}

			
			for(int i = 0; i < n; i++){
				unordered_set < string > :: iterator it = sub_nome[i].begin();
				while( it != sub_nome[i].end() )
				{
					if( (sub_all[*it]-1) == 0 )
					{
						custo_nome[mask][i] = min(custo_nome[mask][i], (int)(*it).size());
					}
					it++;
				} 
			}

			sub_all = aux;
			
		}

		ans = 1e9;

		solve(0, qt.size(), 0, 0);

		cout << ans << '\n';
	}
	return 0;
}