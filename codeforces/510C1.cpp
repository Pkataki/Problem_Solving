#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
string s[100];
int vis[100];
int pre[100];
vector <int> g[30];
int last[100];
int ans = 1;
int size = 0;
void dfs(int p)
{   
    vis[p] = 1;
    pre[p] = 1;
    for (int i = 0; i < g[p].size(); i++) 
    {
        if (!vis[g[p][i]]) dfs(g[p][i]);
        else if (pre[g[p][i]]) ans = 0; 
    }
    pre[p] = 0;
    last[size++] = p; 

}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)  cin >> s[i];
    for (int i = 1; i < n; i++)
    {
        string m1 = s[i - 1];
        string m2 = s[i];
        int j;
        for (j = 0; j < m1.size() && j < m2.size() && m1[j] == m2[j]; j++); 
        if (j < m1.size() && j < m2.size())   
        {
            g[m1[j] - 'a'].push_back(m2[j] - 'a');  
        }
        else if (m1.size() > m2.size())  ans = 0;
    }
    for (int i = 0; i < 26; i++) if (!vis[i]) dfs(i);
    if (ans)
    {
        for (int i = 0; i < size; i++)
        {
            printf("%c",last[i] + 'a');
        }
    }
    else puts("Impossible");
    return 0;
}
