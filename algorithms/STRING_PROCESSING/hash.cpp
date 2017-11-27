#include <bits/stdc++.h>
using namespace std;
vector<int> v;
#define uint64 unsigned long long
uint64 poww[30005], L[2][30005];
 
void powwB()
{
    poww[0] = 1ULL;
    for(int i = 1; i < 30002; i++) poww[i] = poww[i-1]*33;
    char c = 'a';
    for(int i = 0 ; i < 26; i++){ v.push_back(c-'a'); c++; }
    random_shuffle (v.begin(),v.end());
}
string str;
const uint64 C = 5381ULL;
int n;
void Lcalc(int a)
{
    L[a][0] = C;
    if(a)
    	reverse(str.begin(),str.end());
    for(int i = 0 ; i < n ; i++) L[a][i+1] = L[a][i] * 33 + v[str[i]-'a'];    	
}
 
uint64 calc_hash(int a, int b, int dir){
    return (L[dir][b+1] - L[dir][a] * poww[b-a+1]);
}
int f(int x)
{

	return n-x-1;
}

int main()
{
	int k;
	cin >> k;
	cin >> str;
	n = str.size();
	powwB();
	Lcalc(0);
	Lcalc(1);
	int aux = k/2;
	int ans = 0;
    reverse(str.begin(),str.end());
	int dif = 1;
	for(int i = 0; i <  n ; i++)
	{
		//cout << rev[i+aux-dif] << ' ' << rev[i] << " -> " << i+aux-dif << ' ' << i+k << endl;
		if(i+aux-dif < n && i+k-aux < n && i+k-1 < n)
		{
			//cout << i << ' ' << i+aux-dif << " -> " << i+k-aux << ' ' << i+k-1 << endl;
			if(calc_hash(i,i+aux-dif,0) == calc_hash(f(i+k-1),f(i+k-aux),1))
				ans++;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
