#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005, sigma = 26;


int term[MAXN], last[MAXN], to[MAXN][sigma], link[MAXN], sz = 1;
void add(char s[], int id)
{
    int cur = 0;
    for(int i = 0; s[i] ; i++)
    {
        if(!to[cur][s[i] - 'a'])
        {
            to[cur][s[i] - 'a'] = sz++;
            //len[to[cur][c - 'a']] = len[cur] + 1;
        }
        cur = to[cur][s[i] - 'a'];
    }
    term[cur] = id; 
}
 
void push_links()
{
    queue<int>q;
    for(int i = 0; i < sigma; i++)
    {
        if(to[0][i])
            q.push(to[0][i]);
    }
    while(q.size())
    {
        int V = q.front();
        q.pop();
        int U = link[V];
        for(int c = 0; c < sigma; c++)
        {
            if(to[V][c])
            {
                int u = to[V][c];
                link[u] = to[U][c]; 
                last[u] = term[link[u]] ? link[u] : last[link[u]];
                q.push(u);
            }
            else
            {
                to[V][c] = to[U][c];
            }
        }
    }
}

vector<int>ans[100005];

void match(char s[])
{
    int x = 0;
    for(int i = 0; s[i] ; i++)
    {
        x = to[x][s[i] - 'a'];
        int v = x;
        while(v)
        {
            if(term[v])
                ans[term[v]].push_back(i);
            v = last[v];
        }
    }
}

