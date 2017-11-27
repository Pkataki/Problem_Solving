
#include <bits/stdc++.h>
 
using namespace std;
 
vector<string> str(4);
 

int first[5][55][30], sz[5];
map < pair < int, pair < int, pair < int, pair < int, int > > > >, long long > mapa;
 
long long solve(int p1, int p2, int p3, int p4, int final){
	p1 = first[0][p1][final]; p2 = first[1][p2][final];
	p3 = first[2][p3][final]; p4 = first[3][p4][final];
 	if(p1 == -1 || p2 == -1 || p3 == -1 || p4 == -1)return 0;
 	if(mapa.count(make_pair(p1,make_pair(p2,make_pair(p3,make_pair(p4,final)))))) return mapa[make_pair(p1,make_pair(p2,make_pair(p3,make_pair(p4,final))))];
 	long long ret = 1;
 	for(int i = 0; i < 26; i++){
 		ret += solve(p1 + 1, p2 + 1, p3 + 1, p4 + 1, i);
 	}
 
 	return mapa[make_pair(p1,make_pair(p2,make_pair(p3,make_pair(p4,final))))] = ret;
}
 
int main(){
	ios::sync_with_stdio(false);
	for(int i = 0; i < 4; i++){
		getline(cin, str[i]);
		sz[i] = str[i].size();
	}
 
	memset(first, -1, sizeof(first));
 
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < sz[i]; j++){
			for(int k = 0; k < 26; k++){
				for(int u = j; u < sz[i]; u++){
					if(str[i][u] - 'a' == k){
						first[i][j][k] = u;
						break;
					}
				}
			}
		}
	}
 
	long long resp = 0;
	for(int i = 0; i < 26; i++){
	 	resp += solve(0, 0, 0, 0, i);
	}
	cout << resp << "\n";
	return 0;
} 