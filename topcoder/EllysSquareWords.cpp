#include<bits/stdc++.h>
using namespace std;
class EllysSquareWords
{
	public:  int getScore(string S)
	{
		vector<int>cont(27,0);
		for(int i = 0; i < S.size(); i++)
		{
			cont[S[i] - 'A']++;
		}
    
		sort(cont.begin(),cont.end(),greater<int>());
		int ans = 0;
		if(S.size() > 1)
		{
			cont[0] += cont[1];
			cont[1] = 0;
		}
        for(int i = 0; i < 26; i++)
        {    
            ans += cont[i] * cont[i];
        }
		return ans;
	}
};
int main()
{
	EllysSquareWords test;
	cout << "ans = " << test.getScore("TOPCODERROCKS") << "\n";
	return 0;
}