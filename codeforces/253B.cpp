#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ifstream in("input.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

    std::ofstream out("output.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

	int n;
	cin >> n;
	vector<int>v(n);
	vector<int>v1(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	int ans= 100000000;
	for(int i = 0; i < n; i++)
	{
		vector<int>::iterator it = upper_bound(v.begin(),v.end(),2*v[i]);
		int aux = v.end() - it;
		ans = min(ans,i+aux);
	}
	cout << ans << '\n';
}


