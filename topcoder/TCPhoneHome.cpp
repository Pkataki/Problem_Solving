#include <bits/stdc++.h>
using namespace std;
long long c[20][20];
long long pot[18];
class  TCPhoneHome
{
    public : long long validNumbers(int digits, vector <string> specialPrefixes)
    {
        vector<int>v;
        pot[0] = 1LL;
        for(int i = 1; i <= 17; i++)
        {
            pot[i] = pot[i-1] * 10LL;
        }
        set<string>ss;
        for(auto s: specialPrefixes)
        {
            ss.insert(s);
        }
        for(auto it : ss)
        {
            string aux = "";
            bool ok = 1;
            for(int i = 0; i < it.size(); i++)
            {
                aux += it[i];
                if(ss.count(aux))
                {
                    ok = 0;
                    continue;
                }
            }
            if(ok)
                v.push_back(it.size());

        }
        long long ans1 = 0;
        cout << v.size() << " ** welton delicia " << endl;
        for(int i = 0; i < v.size(); i++)
        {
            ans1 += pot[digits - v[i]];
        }
        return pot[digits] - ans1;
    }
};
int main()
{

    return 0;
}