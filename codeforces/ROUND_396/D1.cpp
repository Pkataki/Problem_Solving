#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define repi(a, i, n) for( int i = a ; i < n ; i++)
#define repj(a, j, n) for( int j = a ; j < n ; j++)
#define rrep(a, i, n) for( int i = n ; i >= a; i--)
#define mp make_pair
#define pb push_back
#define S second
#define F first
#define inf 0x3f
#define MAX 1000001
#define teste cout << "testando **********\n"
#define ll  long long
#define ld  long double

typedef  vector<int> vi;
typedef  vector<double> vd;
typedef pair<int, int> pii;
typedef  pair<double, double> pdd;
typedef  pair< int, double> pid;
typedef  pair< double, int> pdi;
typedef map<int, int> mii;

vector<int>pai;
int find(int x){
	if( pai[x] != x)
		pai[x] = find(pai[x]);
	return pai[x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m, q;
	cin >> n >> m >> q;
	pai = vector<int>(n*2+1);
	map<string, int> pos;
	for( int i = 0 ; i < n; i++){
		string s;
		cin >> s;
		pos[s] = i;
		pai[i] = i;
                pai[i+n] = i+n;
	}
	for( int i = 0 ; i < m; i++){
		int t; cin >> t;
		string a, b;
		cin >> a >> b;
                int x = pos[a];
                int y = pos[b];
		if( t == 1){
                    if( find(x) == find(y+n)){
                        cout << "NO\n";
                        continue;
                    }
                    pai[find(x)] = find(y);
                    pai[find(x+n)] = find(y+n);
                    cout << "YES\n";
		}
		else{
                        if(find(x+n) == find(y+n)){
                            cout << "NO\n";
                            continue;
                        }
                        cout << "YES\n";
			pai[find(x)] = find(y+n);
                        pai[find(x+n)] = find(y);
		}
	}
	for( int i = 0 ; i < q; i++){
                string a, b;
                cin >> a >> b;
                int x = pos[a], y = pos[b];
                if( find(x) == find(y))
                    cout << "1\n";
                else if( find(x) == find(y+n))
                    cout << "2\n";
                else
                    cout << "3\n";
        }
	return 0;
}
